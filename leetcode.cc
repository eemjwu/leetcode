#include "leetcode.h"
#include <numeric>
#include "common_tool.h"

using namespace std;
// 1
void Solution::RunCode1(std::vector<int> &input) {
  CommonTool::PrintVector<int>("input", input);
  std::vector res = runningSum(input);
  CommonTool::PrintVector<int>("result", res);
}
std::vector<int> Solution::runningSum(std::vector<int> &nums) {
  for (int index(1); index < nums.size(); ++index) {
    nums[index] += nums[index - 1];
  }
  return nums;
}

// 2
void Solution::RunCode2(std::vector<int> &input) {
  CommonTool::PrintVector<int>("input", input);
  int res_index = pivotIndex(input);
  cout << res_index << endl;
}
int Solution::pivotIndex(std::vector<int> &nums) {
  if (nums.size() < 2) return 0;
  // 求和
  int sum = std::accumulate(nums.begin(), nums.end(), 0);
  int sum_left(0);
  for (int index = 0; index < nums.size(); ++index) {
    if (index > 0) sum_left += nums[index - 1];
    // sum_right
    if (sum - sum_left - nums[index] == sum_left) return index;
  }
  return -1;
}
