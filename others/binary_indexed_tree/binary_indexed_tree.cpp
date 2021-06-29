#include <vector>
#include <iostream>

using namespace std;

//* query(), init(), update() depend on the problem
//* implement the prefix sum as default
class Bit {
  //* N = number of input elements
  int N;
  //* bit [1, N]
  vector<int> bit;

 public:
  int lowbit(int x) { return x & (-x); }

  //* query an interval [1, x] from bit
  //* 1 <= x <= N
  int query(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
      sum += bit[i];
    }

    return sum;
  }

  //* query an interval [a, b] from bit
  //* 1 <= a <= b <= N
  int query(int a, int b) { return query(b) - query(a - 1); }

  //* update val from x to it's parents
  void update(int x, int val) {
    for (int i = x; i <= N; i += lowbit(i)) {
      bit[i] += val;
    }
  }
  
  void init(vector<int>& nums) {
    N = nums.size();

    for (int i = 0; i <= N; i++) {
      bit.push_back(0);
    }
    for (int i = 1; i <= N; i++) {
      bit[i] = nums[i - 1];

      int parent = i + lowbit(i);
      if (parent <= N) {
        bit[parent] += bit[i];
      }
    }
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  Bit bit;
  bit.init(nums);

  cout << bit.query(1, nums.size()) << "\n";
  cout << bit.query(2, nums.size()) << "\n";

  bit.update(1, 2);
  cout << bit.query(1, nums.size()) << "\n";
  cout << bit.query(2, nums.size()) << "\n";
}