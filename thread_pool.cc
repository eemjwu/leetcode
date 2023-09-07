#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

class ThreadPool {
    public:
    ThreadPool(size_t size);
    void enqueue(std::function<void()>f);
    ~ThreadPool();
    private:
    std::vector<std::thread> workers_;
    std::queue<std::function<void()>> tasks_;
    std::mutex queue_mutex_;
    std::condition_variable cv_;
    bool stop_;
};

ThreadPool::ThreadPool(size_t size) : stop_(false) {
    for(size_t i = 0; i<size;++i) {
        workers_.emplace_back([this]{
            for(;;){
                std::function<void()> task;
                // 等待获取任务执行
                {
                    std::unique_lock<std::mutex> lock(queue_mutex_);
                    cv_.wait(lock, [this]{return stop_ || !tasks_.empty();});
                    if(stop_ && tasks_.empty())
                        return;
                    task = std::move(tasks_.front());
                    tasks_.pop();
                }
                // 执行
                task();
            }
        });
    }
}

void ThreadPool::enqueue(std::function<void()> f) {
    {
        std::unique_lock<std::mutex> lock(queue_mutex_);
        if(stop_) throw std::runtime_error("thread pool stopped");
        tasks_.emplace(f);
    }
    // 关键
    cv_.notify_one();
}

ThreadPool::~ThreadPool(){
    {
        std::unique_lock<std::mutex> lock(queue_mutex_);
        stop_ = true;
    }
    cv_.notify_all();
    for(std::thread &worker : workers_) {
        worker.join();
    }
}