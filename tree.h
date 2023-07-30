#pragma once

#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class TreeSolution {
 public:
  // 前序遍历 递归
  vector<int> PreorderTraversal(TreeNode* root);
  // 前序遍历 循环
  vector<int> PreorderTraversalCyc(TreeNode* root);
  // 中序遍历 递归
  vector<int> InorderTraversal(TreeNode* root);
  // 中序遍历 循环
  vector<int> InorderTraversalCyc(TreeNode* root);
  // 后序遍历 递归
  vector<int> PostorderTraversal(TreeNode* root);
  // 后序遍历 循环
  vector<int> PostorderTraversalCyc(TreeNode* root);
  // 层序遍历
  vector<int> LevelorderTraversal(TreeNode* root);

 private:
  void PreorderTraversal(TreeNode* root, vector<int>& res);
  void InorderTraversal(TreeNode* root, vector<int>& res);
};