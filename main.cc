#include <iostream>
#include <vector>
#include <sstream>
#include "leetcode.h"
#include "sort.h"
#include "tree.h"

using namespace std;

void print_vec(const vector<int>& vec) {
  std::stringstream ss;
  for (int i = 0; i < vec.size(); i++) {
    if (i > 0) {
      ss << ",";
    }
    ss << vec[i];
  }
  std::string str = ss.str();
  std::cout << str << std::endl;
}

void test_tree() {
  // 只有根节点的树
  TreeNode* root1 = new TreeNode(1);

  // 完全二叉树
  //     1
  //    / \
  //   2   3
  //  / \ / \
  // 4  5 6  7
  TreeNode* root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(3);
  root2->left->left = new TreeNode(4);
  root2->left->right = new TreeNode(5);
  root2->right->left = new TreeNode(6);
  root2->right->right = new TreeNode(7);

  // 左斜树
  //       1
  //      /
  //     2
  //    /
  //   3
  //  /
  // 4
  TreeNode* root3 = new TreeNode(1);
  root3->left = new TreeNode(2);
  root3->left->left = new TreeNode(3);
  root3->left->left->left = new TreeNode(4);

  // 右斜树
  // 1
  //  \
  //   2
  //    \
  //     3
  //      \
  //       4
  TreeNode* root4 = new TreeNode(1);
  root4->right = new TreeNode(2);
  root4->right->right = new TreeNode(3);
  root4->right->right->right = new TreeNode(4);
  //   // 前序遍历
  //   {
  //     TreeSolution solution;
  //     vector<int> res1 = solution.PreorderTraversal(root1);
  //     print_vec(res1);
  //     vector<int> res2 = solution.PreorderTraversal(root2);
  //     print_vec(res2);
  //     vector<int> res3 = solution.PreorderTraversal(root3);
  //     print_vec(res3);
  //     vector<int> res4 = solution.PreorderTraversal(root4);
  //     print_vec(res4);
  //   }
    // 前序遍历 循环
    {
      TreeSolution solution;
      vector<int> res1 = solution.PreorderTraversalCyc(root1);
      print_vec(res1);
      vector<int> res2 = solution.PreorderTraversalCyc(root2);
      print_vec(res2);
      vector<int> res3 = solution.PreorderTraversalCyc(root3);
      print_vec(res3);
      vector<int> res4 = solution.PreorderTraversalCyc(root4);
      print_vec(res4);
    }
  //   // 中序遍历
  //   {
  //     TreeSolution solution;
  //     vector<int> res1 = solution.InorderTraversal(root1);
  //     print_vec(res1);
  //     vector<int> res2 = solution.InorderTraversal(root2);
  //     print_vec(res2);
  //     vector<int> res3 = solution.InorderTraversal(root3);
  //     print_vec(res3);
  //     vector<int> res4 = solution.InorderTraversal(root4);
  //     print_vec(res4);
  //   }
    // 中序遍历 循环
    {
      TreeSolution solution;
      vector<int> res1 = solution.InorderTraversalCyc(root1);
      print_vec(res1);
      vector<int> res2 = solution.InorderTraversalCyc(root2);
      print_vec(res2);
      vector<int> res3 = solution.InorderTraversalCyc(root3);
      print_vec(res3);
      vector<int> res4 = solution.InorderTraversalCyc(root4);
      print_vec(res4);
    }
  // // 后遍历
  // {
  //   TreeSolution solution;
  //   vector<int> res1 = solution.PostorderTraversal(root1);
  //   print_vec(res1);
  //   vector<int> res2 = solution.PostorderTraversal(root2);
  //   print_vec(res2);
  //   vector<int> res3 = solution.PostorderTraversal(root3);
  //   print_vec(res3);
  //   vector<int> res4 = solution.PostorderTraversal(root4);
  //   print_vec(res4);
  // }
  // 后遍历 循环
  {
    TreeSolution solution;
    vector<int> res1 = solution.PostorderTraversalCyc(root1);
    print_vec(res1);
    vector<int> res2 = solution.PostorderTraversalCyc(root2);
    print_vec(res2);
    vector<int> res3 = solution.PostorderTraversalCyc(root3);
    print_vec(res3);
    vector<int> res4 = solution.PostorderTraversalCyc(root4);
    print_vec(res4);
  }
}

int main() {
  // Solution solution;
  // vector<int> input{1, 2, 3, 4};
  // solution.RunCode1(input);

  // vector<int> input2{1, 7, 3, 6, 5, 6};
  // solution.RunCode2(input2);
  // // 冒泡排序
  // {
  //   vector<int> input{1, 7, 3, 10086, 6, 5, 34, 55, 23, 6, 7, 9, 2, 1, 44, 5, 6, 78, 9, 653};
  //   SortSolution sort;
  //   sort.BubbleSort(input);
  //   print_vec(input);
  // }
  // 插入排序
  // {
  //   vector<int> input{1, 7, 3, 10086, 6, 5, 34, 55, 23, 6, 7, 9, 2, 1, 44, 5, 6, 78, 9, 653};
  //   SortSolution sort;
  //   sort.InsertSort(input);
  //   print_vec(input);
  // }

  // 归并排序
  // {
  //   vector<int> input{1, 7, 3, 6, 5, 34, 55, 23, 6, 7, 9, 2, 1, 44, 5, 6, 78, 9, 653};
  //   SortSolution sort;
  //   sort.MergeSort(input);
  //   print_vec(input);
  // }
  // 归并排序 循环
  // {
  //   vector<int> input{1, 7, 3, 10086, 6, 5, 34, 55, 23, 6, 7, 9, 2, 1, 44, 5, 6, 78, 9, 653};
  //   SortSolution sort;
  //   sort.MergeSortCyc(input);
  //   print_vec(input);
  // }
  // 快排
  // {
  //   vector<int> input{1, 7, 3,10086, 6, 5, 34, 55, 23, 6, 7, 9, 2, 1, 44, 5, 6, 78, 9, 653};
  //   SortSolution sort;
  //   sort.QuikSort(input);
  //   print_vec(input);
  // }
  // 快排 循环
  // {
  //   vector<int> input{1, 7, 3, 10086, 6, 5, 34, 55, 23, 6, 7, 9, 2, 1, 44, 5, 6, 78, 9, 653};
  //   SortSolution sort;
  //   sort.QuikSortCyc(input);
  //   print_vec(input);
  // }
  // 堆排
  // {
  //   vector<int> input{1, 7, 3, 10086, 6, 5, 34, 55, 23, 6, 7, 9, 2, 1, 44, 5, 6, 78, 9, 653};
  //   SortSolution sort;
  //   sort.HeapSort(input);
  //   print_vec(input);
  // }
  // 测试树的遍历
  test_tree();
}