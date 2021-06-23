// Time complexity: O(N)
// Space complexity: O(1)
// N: size of nums
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int N = nums.size();
    if (N == 0) return 0;
    int ans = 1, maxNum = nums[0];
    for (int i = 1; i < N; i++) {
      if (nums[i] > maxNum) {
        maxNum = nums[i];
        swap(nums[i], nums[ans]);
        ++ans;
      }
    }

    return ans;
  }
};

// Time complexity: O(N)
// Space complexity: O(1)
// N: size of nums
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int fast = 0, slow = 0;

    while (fast < nums.size()) {
      while (nums[fast] != nums[slow]) {
        ++slow;
        nums[slow] = nums[fast];
      }
      ++fast;
    }
    return slow + 1;
  }
};