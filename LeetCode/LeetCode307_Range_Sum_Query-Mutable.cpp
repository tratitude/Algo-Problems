// Binary Indexed Tree Approach
// Time complexity:
// NumArray(): O(N)
// update(), sumRange(): O(log(N))
// N: size of nums
class NumArray {
  int N;
  // [1, N]
  vector<int> bit;
  vector<int> base;

  int lowbit(int x) { return x & (-x); }

  // index [0, N]
  int sumBegin(int index) {
    int sum = 0;
    for (int i = index; i > 0; i -= lowbit(i)) {
      sum += bit[i];
    }

    return sum;
  }

 public:
  NumArray(vector<int>& nums) {
    N = nums.size();
    base = ref(nums);
    bit.reserve(N + 1);
    for (int i = 0; i <= N; i++) {
      bit.push_back(0);
    }

    for (int i = 0; i < N; i++) {
      bit[i + 1] += nums[i];
      int y = i + 1 + lowbit(i + 1);
      if (y <= N) {
        bit[y] += bit[i + 1];
      }
    }
  }

  // input index in [0, N - 1]
  void update(int index, int val) {
    int diff = val - base[index];
    // update base
    base[index] = val;

    for (int i = index + 1; i <= N; i += lowbit(i)) {
      bit[i] += diff;
      // cout << i << " " << bit[i] << "\n";
    }
  }

  // input index in [0, N - 1]
  int sumRange(int left, int right) {
    return sumBegin(right + 1) - sumBegin(left);
  }
};