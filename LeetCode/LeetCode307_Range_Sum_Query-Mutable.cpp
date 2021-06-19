#include <vector>
#include <iostream>
using namespace std;
// [Fenwick tree](https://www.csie.ntu.edu.tw/~sprout/algo2016/homework/week11.pdf)
// WA and need more working on.... binary indexed tree
class NumArray {
  vector<int> bit;
  int N;
  int lowbit(int x) { return x & (~x + 1); }

 public:
  NumArray(vector<int>& nums) {
    N = nums.size();
    bit.push_back(0);
    for (int x = 1; x <= N; x++) {
      bit.push_back(nums[x-1]);
      int y = x - lowbit(x);
      for (int i = x - 1; i > y; i -= lowbit(i)) {
        bit[x] += bit[i];
      }
    }
  }

  void update(int index, int val) {
    int diff = val - bit[index + 1];
    for (int i = index + 1; i <= N; i += lowbit(i)) {
      bit[i] += diff;
    }
  }

  int sumRange(int left, int right) {
    int sum = 0;
    for (int i = right + 1; i >= left + 1; i -= lowbit(i)) {
      sum += bit[i];
    }
    return sum;
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main()
{
  vector<int> nums = {1, 3, 5};
  NumArray arr(nums);
  cout << arr.sumRange(0, 2) << "\n";
  arr.update(1, 2);
  cout << arr.sumRange(0, 2) << "\n";
}