#pragma once

#include <vector>

using namespace std;

class SortSolution {
 public:
  // 冒泡排序
  std::vector<int> BubbleSort(vector<int>& input);
  // 插入排序
  std::vector<int> InsertSort(vector<int>& input);
  // 归并排序 递归
  std::vector<int> MergeSort(vector<int>& input);
  // 归并排序 循环
  std::vector<int> MergeSortCyc(vector<int>& input);
  // 快速排序 递归
  std::vector<int> QuikSort(vector<int>& input);
  // 快速排序 循环
  std::vector<int> QuikSortCyc(vector<int>& input);
  // 堆排序
  std::vector<int> HeapSort(vector<int>& input);

 private:
  void merge(vector<int>& input, int begin, int mid, int end);
  void merge_sort_c(vector<int>& input, int begin, int end);

  int partition(vector<int>& input, int begin, int end);
  void quik_sort_c(vector<int>& input, int begin, int end);

  void perdown(vector<int>& input, int begin, int n);
};