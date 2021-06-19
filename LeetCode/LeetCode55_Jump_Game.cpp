// Time complexity: O(N)
// Space complexity: O(1)
// N: size of nums
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int N = nums.size();
    int farthest = 0;
    for (int i = 0; i < N - 1; i++) {
      farthest = max(farthest, nums[i] + i);
      if (farthest <= i) {
        return false;
      }
    }
    return farthest >= N - 1;
  }
};