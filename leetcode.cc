#include "leetcode.h"
#include "common_tool.h"

using namespace std;
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
