#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <sstream>
#include <stack>
#include <string>
#include <mutex>
#include <condition_variable>
#include <vector>

using namespace std;

std::mutex lock;

class myLock{
  public:
  myLock(){};
  bool rLock(){
    unique_lock<std::mutex> lock(m);
    cv.wait(lock, [this]() { return write_lock; });

    read_lock_count++;
    return true;
  }
  bool wLock(){
    unique_lock<std::mutex> lock(m);

    if(read_lock_count !=0 || write_lock ){
      return false;
    }
    write_lock = true;
    return true;
  }

  bool read_unlock(){
    unique_lock<std::mutex> lock(m);
    if (read_lock_count == 0) return false;
    read_lock_count--;
    return true;
  }

  bool write_unlock(){
    unique_lock<std::mutex> lock(m);
    if (!write_lock) return false;
    write_lock = false;
    return true;
  }

  private:
   std::mutex m;
   std::condition_variable cv;
   int read_lock_count;
   bool write_lock;

}