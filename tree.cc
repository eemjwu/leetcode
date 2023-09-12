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
    if (ptr != nullptr) {
      res.push_back(ptr->val);
      stk.push(ptr);
      ptr = ptr->left;
    } else {
      ptr = stk.top();
      stk.pop();
      ptr = ptr->right;
    }
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
    if (ptr) {
      stk.push(ptr);
      ptr = ptr->left;
    } else {
      ptr = stk.top();
      stk.pop();
      res.push_back(ptr->val);
      ptr = ptr->right;
    }
  }
  return res;
}

void realPostorderTraversal(TreeNode* root, vector<int>& res) {
  if (root == nullptr) return;
  realPostorderTraversal(root->left, res);
  realPostorderTraversal(root->right, res);
  res.push_back(root->val);
}
// 后序遍历 递归
vector<int> TreeSolution::PostorderTraversal(TreeNode* root) {
  if (root == nullptr) return {};
  vector<int> res;
  realPostorderTraversal(root, res);
  return res;
}
void realPostorderTraversalCyc(TreeNode* root, vector<int>& res) {
  if (root == nullptr) return;
  stack<TreeNode*> help_s;
  TreeNode* cur = root;
  TreeNode* pre = nullptr;

  while (!help_s.empty() || cur != nullptr) {
    if (cur != nullptr) {
      help_s.push(cur);
      cur = cur->left;
    } else {
      // 此时暂时不弹出，判断之前已经遍历过右子节点，才弹出
      cur = help_s.top();
      if (cur->right == nullptr || cur->right == pre) {
        help_s.pop();
        res.push_back(cur->val);
        pre = cur;  // 记录当前访问的节点
        // point: 设置当前访问的为空，后序循环将处理处理栈中元素
        // 当前的根已经处理了，说明当前节点的 左 右 根 都被处理了，下次处理栈中之前push的上层元素
        cur = nullptr;
      } else {
        cur = cur->right;  // 当前节点的右子树还没处理，先处理右子树
      }
    }
  }
}
// 后序遍历 循环
vector<int> TreeSolution::PostorderTraversalCyc(TreeNode* root) {
  if (root == nullptr) return {};
  vector<int> res;
  realPostorderTraversalCyc(root, res);
  return res;
}
// 层序遍历
vector<int> TreeSolution::LevelorderTraversal(TreeNode* root) {}