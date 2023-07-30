#include "tree.h"
#include <stack>
void TreeSolution::PreorderTraversal(TreeNode* root, vector<int>& res) {
  if (root == nullptr) return;
  res.push_back(root->val);
  PreorderTraversal(root->left, res);
  PreorderTraversal(root->right, res);
}

// 前序遍历 递归
vector<int> TreeSolution::PreorderTraversal(TreeNode* root) {
  vector<int> result;
  PreorderTraversal(root, result);
  return result;
}
// 前序遍历 循环
vector<int> TreeSolution::PreorderTraversalCyc(TreeNode* root) {
  vector<int> res;
  TreeNode* ptr = root;
  stack<TreeNode*> stk;
  while (!stk.empty() || ptr) {
    while (ptr != nullptr) {
      res.push_back(ptr->val);
      stk.push(ptr);
      ptr = ptr->left;
    }
    ptr = stk.top();
    stk.pop();
    ptr = ptr->right;
  }
  return res;
}

void TreeSolution::InorderTraversal(TreeNode* root, vector<int>& res) {
  if (root == nullptr) return;
  InorderTraversal(root->left, res);
  res.push_back(root->val);
  InorderTraversal(root->right, res);
}

// 中序遍历 递归
vector<int> TreeSolution::InorderTraversal(TreeNode* root) {
  vector<int> result;
  InorderTraversal(root, result);
  return result;
}
// 中序遍历 循环
vector<int> TreeSolution::InorderTraversalCyc(TreeNode* root) {
  vector<int> res;
  TreeNode* ptr = root;
  stack<TreeNode*> stk;
  while (!stk.empty() || ptr) {
    while (ptr) {
      stk.push(ptr);
      ptr = ptr->left;
    }
    ptr = stk.top();
    stk.pop();
    res.push_back(ptr->val);
    ptr = ptr->right;
  }
  return res;
}
// 后序遍历 递归
vector<int> TreeSolution::PostorderTraversal(TreeNode* root) {}
// 后序遍历 循环
vector<int> TreeSolution::PostorderTraversalCyc(TreeNode* root) {}
// 层序遍历
vector<int> TreeSolution::LevelorderTraversal(TreeNode* root) {}