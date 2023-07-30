#include "sort.h"
#include <iostream>
#include <stack>

std::vector<int> SortSolution::BubbleSort(vector<int>& input) {
  if (input.size() == 0) return {};
  int n = input.size();
  bool has_swap(false);

  // 定义排序好的元素的右边界
  for (int end = n - 1; end >= 0; --end) {
    has_swap = false;
    for (int i = 0; i < end; ++i) {
      if (input[i] > input[i + 1]) {
        swap(input[i], input[i + 1]);
        has_swap = true;
      }
    }
    if (!has_swap) {
      // 未发生交换已经有序
      break;
    }
  }
  return input;
}

std::vector<int> SortSolution::InsertSort(vector<int>& input) {
  if (input.size() == 0) return {};
  int n = input.size();

  // 摸一张新牌
  for (int i = 1; i < n; ++i) {
    // 依次寻找合适的位置
    int pivot = input[i];
    for (int j = i - 1; j >= 0; --j) {
      if (input[j] > pivot) {
        input[j + 1] = input[j];
      } else {
        input[j + 1] = pivot;
        break;
      }
    }
  }
  return input;
}

void SortSolution::merge(vector<int>& input, int begin, int mid, int end) {
  vector<int> merged(end - begin + 1);
  int k(0), i(begin), j(mid + 1);
  while (i <= mid && j <= end) {
    if (input[i] < input[j]) {
      merged[k++] = input[i++];
    } else {
      merged[k++] = input[j++];
    }
  }
  if (i <= mid) {
    while (i <= mid) {
      merged[k++] = input[i++];
    }
  }
  if (j <= end) {
    while (j <= end) {
      merged[k++] = input[j++];
    }
  }
  for (auto item : merged) {
    input[begin++] = item;
  }
}

void SortSolution::merge_sort_c(vector<int>& input, int begin, int end) {
  if (begin >= end) return;
  int mid = begin + ((end - begin) >> 1);
  merge_sort_c(input, begin, mid);
  merge_sort_c(input, mid + 1, end);
  merge(input, begin, mid, end);
}

std::vector<int> SortSolution::MergeSort(vector<int>& input) {
  if (input.size() == 0) return input;
  merge_sort_c(input, 0, input.size() - 1);
  return input;
}

std::vector<int> SortSolution::MergeSortCyc(vector<int>& input) {
  if (input.size() == 0) return {};
  int n = input.size();
  for (int step = 1; step < n; step *= 2) {
    for (int left = 0; left < n; left = left + 2 * step) {
      // 左边的结尾
      int mid = min(left + step, n) - 1;
      // 右边的结尾
      int right = min(left + 2 * step, n) - 1;
      int i(left), j(mid + 1), k(0);
      vector<int> merged(2 * step);
      while (i <= mid && j <= right) {
        if (input[i] < input[j]) {
          merged[k++] = input[i++];
        } else {
          merged[k++] = input[j++];
        }
      }
      if (i <= mid) {
        while (i <= mid) {
          merged[k++] = input[i++];
        }
      }
      if (j <= right) {
        while (j <= right) {
          merged[k++] = input[j++];
        }
      }
      i = left;
      for (auto itm : merged) {
        input[i++] = itm;
      }
    }
  }
  return input;
}

int SortSolution::partition(vector<int>& input, int begin, int end) {
  int pivot = input[end];
  // i 指向第一个大于等于pivot的位置
  int i(begin);
  for (int j = i; j < end; ++j) {
    if (input[j] < pivot) {
      swap(input[i], input[j]);
      i++;
    }
  }
  // 将 pivot 放到正确的位置
  swap(input[i], input[end]);
  return i;
}

void SortSolution::quik_sort_c(vector<int>& input, int begin, int end) {
  if (begin >= end) return;
  // 随机找一个数放到最末位
  swap(input[end], input[begin + (rand() % (end - begin + 1))]);
  int pos = partition(input, begin, end);
  quik_sort_c(input, begin, pos - 1);
  quik_sort_c(input, pos + 1, end);
}

std::vector<int> SortSolution::QuikSort(vector<int>& input) {
  if (input.size() == 0) return input;

  quik_sort_c(input, 0, input.size() - 1);
  return input;
}

std::vector<int> SortSolution::QuikSortCyc(vector<int>& input) {
  if (input.size() == 0) return {};
  int n = input.size();
  // 辅助栈，保存下次需要计算的左右边界, 注意入栈顺序
  stack<int> stk;
  // 首先对 0 ～ n-1 做 partition
  stk.push(n - 1);
  stk.push(0);
  while (!stk.empty()) {
    int left = stk.top();
    stk.pop();
    int right = stk.top();
    stk.pop();
    // 注意 无效的区间直接跳过
    if (left >= right) continue;
    // 随机选一个元素替换最后一个元素 作为基准
    swap(input[right], input[left + rand() % (right - left + 1)]);
    int pivot = input[right];
    // partition
    // i 指向第一个大于等于pivot位置
    int i(left);
    for (int j = left; j < right; ++j) {
      if (input[j] < pivot) {
        swap(input[j], input[i]);
        i++;
      }
    }
    // 把pivot放到正确的位置i
    swap(input[i], input[right]);

    // push 下次需要计算的区间, 注意弹出的先后顺序
    stk.push(right);
    stk.push(i + 1);

    stk.push(i - 1);
    stk.push(left);
  }
  return input;
}

// input:输入数组
// begin: 需要调整的位置
// n: 数组的元素总个数
void SortSolution::perdown(vector<int>& input, int begin, int n) {
  if (n <= 0) return;
  int pivot = input[begin];
  int parent = begin;
  int child = 2 * parent + 1;
  for (; child < n; parent = child,child = 2 * parent + 1) {
    // 找到子节点更大的作为对象
    if (child + 1 < n && input[child + 1] > input[child]){
      child++;
    }
    if(input[child] > pivot) {
      swap(input[child], input[parent]);
    }else{
      // 找到了pivot可以放置的位置
      break;
    }
  }
}

std::vector<int> SortSolution::HeapSort(vector<int>& input){
  if (input.size() == 0) return {};
  int n = input.size();
  // 从最后一个子节点的父节点开始调整为最大堆
  for (int i = n / 2 - 1; i >= 0; --i) {
    perdown(input, i, n);
  }

  for (int left_count = n; left_count > 0;left_count--) {
    // 将堆顶最大元素，放到最后去
    swap(input[0], input[left_count - 1]);
    // 调整剩下的元素为最大堆
    perdown(input, 0, left_count - 1);
  }
  return input;
}