
#pragma once

#include <iostream>
#include <string>
#include <vector>
/*
** 链表 8: 
*********   2.两数相加
            19. 删除链表的倒数第 N 个结点
            116. 填充每个节点的下一个右侧节点指针
            138. 复制带随机指针的链表
            146. LRU 缓存
            148. 排序链表                       [x]
            237. 删除链表中的节点
            328. 奇偶链表
** 最 11:
*********   3. 无重复字符的最长子串
            5. 最长回文子串
            11. 盛最多水的容器
            53. 最大子数组和
            128. 最长连续序列
            152. 乘积最大子数组
            155. 最小栈
            179. 最大数
            215. 数组中的第K个最大元素
            300. 最长递增子序列
            395. 至少有 K 个重复字符的最长子串
*/

class Solution {
 public:
  // 按 leetcode 题目顺序排列，每个题目包含执行器和具体实现
  // 1
  void RunCode1(std::vector<int> &input);
  std::vector<int> runningSum(std::vector<int> &nums);
  // 2
  void RunCode2(std::vector<int> &input);
  int pivotIndex(std::vector<int>& nums);

 private:
};