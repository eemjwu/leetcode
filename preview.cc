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
#include <thread>

using namespace std;

#include <iostream>
#include <vector>

// 生成回文数
std::vector<long long> generatePalindromes(int n) {
    // 初始化回文数列表，先添加0和所有一位数
    std::vector<long long> palindromes = {0};
    for (int i = 1; i < 10; ++i) {
        palindromes.push_back(i);
    }

    // 对于每一个位数，从1到n
    for (int i = 1; i <= n; ++i) {
        // 获取当前回文数列表的大小
        int size = palindromes.size();
        // 从列表的末尾开始，向前遍历
        for (int j = size - 1; j >= 0; --j) {
            // 获取当前回文数
            long long num = palindromes[j];
            // 如果当前回文数已经达到10位，就跳过
            if (num >= 1000000000) continue;
            // 初始化新的回文数的最后一位数字
            int digit = 0, tmp = num;
            // 对当前回文数的每一位进行操作
            while (tmp > 0) {
                // 获取当前位的数字
                digit = tmp % 10;
                // 去掉当前位的数字
                tmp /= 10;
                // 将当前位的数字添加到新的回文数的末尾
                num = num * 10 + digit;
                // 如果新的回文数小于或等于9876543210，就添加到列表中
                if (num <= 9876543210) {
                    palindromes.push_back(num);
                }
            }
        }
    }

    // 返回回文数列表
    return palindromes;
}

int main() {
    // 生成所有小于或等于10位的回文数
    std::vector<long long> palindromes = generatePalindromes(2);
    for(auto i : palindromes) {
      cout << i << endl;
    }
    // 输出回文数的总数
    std::cout << "Total palindrome numbers: " << palindromes.size() << std::endl;
    return 0;
}
