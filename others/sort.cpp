#include <deque>
#include <functional>
#include <iostream>
#include <vector>


// Heap sort
// Time complexity: O(nlon(n)), Space complexity: O(1)
// 想法:
// 順序是從樹的底部(子問題)到頂，確保底部是正確的，遇到要更動的再往下更動，能確保性質是完整的
//       變成heap之後，最頂部是正確答案，與底部交換，存在底部的到最頂，再Heapify最頂一次，找下一個
// 注意: cmp(a,b) if a ? b return true，因為答案存在最後面，大小會反轉
template <typename T>
void heapify(std::vector<T> &vec, std::size_t start, std::size_t end,
             std::function<bool(const T &, const T &)> cmp) {
  std::size_t dad = start, son = start * 2 + 1;
  while (son <= end) {
    // select the greatest son, reverse the cmp
    if (son + 1 <= end && !cmp(vec[son + 1], vec[son])) ++son;
    // check
    if (!cmp(vec[dad], vec[son])) {
      return;
    } else {
      std::swap(vec[dad], vec[son]);
      dad = son;
      son = dad * 2 + 1;
    }
  }
}
template <typename T>
void heap_sort(std::vector<T> &vec,
               std::function<bool(const T &, const T &)> cmp) {
  // make it to heap
  // counter i can't be std::size_t otherwise will underflow
  for (int i = vec.size() / 2 - 1; i >= 0; --i) {
    heapify(vec, i, vec.size() - 1, cmp);
  }
  // store the sorted number from bottom up
  for (int i = vec.size() - 1; i >= 0; --i) {
    std::swap(vec[i], vec[0]);
    heapify(vec, 0, i - 1, cmp);
  }
}
// Merge sort - recursive version
// Time complexity: O(nlog(n)), Space complexity: O(nlog(n))
template <typename T>
void merge_sort_recursive(std::vector<T> &vec, std::size_t start,
                          std::size_t end,
                          std::function<bool(const T &, const T &)> cmp) {
  if (start == end) return;
  std::size_t mid = (start + end) / 2;
  merge_sort_recursive(vec, start, mid, cmp);
  merge_sort_recursive(vec, mid + 1, end, cmp);

  // merge
  std::deque<int> subL(vec.begin() + start, vec.begin() + mid + 1);
  std::deque<int> subR(vec.begin() + mid + 1, vec.begin() + end + 1);
  for (std::size_t i = start; i <= end; ++i) {
    if (subL.empty()) {
      vec[i] = subR.front();
      subR.pop_front();
    } else if (subR.empty()) {
      vec[i] = subL.front();
      subL.pop_front();
    } else {
      if (cmp(subL.front(), subR.front())) {
        vec[i] = subL.front();
        subL.pop_front();
      } else {
        vec[i] = subR.front();
        subR.pop_front();
      }
    }
  }
}
template <typename T>
void merge_sort_recursive(std::vector<T> &vec,
                          std::function<bool(const T &, const T &)> cmp) {
  merge_sort_recursive(vec, 0, vec.size() - 1, cmp);
}
// Quick sort
// Time complexity:
// 心得: 用unsigned當作counter要非常小心，容易underflow
template <typename T>
void quick_sort(std::vector<T> &vec, int start, int end,
                std::function<bool(const T &, const T &)> cmp) {
  if (start >= end) return;

  // int headL = start+1, headR = end;   // wrong answer
  int headL = start, headR = end;
  while (headL != headR) {
    while (cmp(vec[headL], vec[start]) && headL < headR) ++headL;
    while (!cmp(vec[headR], vec[start]) && headL < headR) --headR;
    std::swap(vec[headL], vec[headR]);
  }

  std::swap(vec[start], vec[headL]);
  quick_sort(vec, start, headL - 1, cmp);
  quick_sort(vec, headR + 1, end, cmp);
}
template <typename T>
void quick_sort(std::vector<T> &vec,
                std::function<bool(const T &, const T &)> cmp) {
  quick_sort(vec, 0, vec.size() - 1, cmp);
}
template <typename T>
void print(const std::vector<T> &vec) {
  for (const auto &v : vec) {
    std::cout << v << "\n";
  }
  std::cout << "-----------------------------\n";
}
int main() {
  std::vector<int> vec = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7,
                          0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
  // heap_sort<int>(vec, std::less<int>());
  // print(vec);
  // merge_sort_recursive<int>(vec, std::greater<int>());
  // print(vec);
  quick_sort<int>(vec, std::greater<int>());
  print(vec);
}