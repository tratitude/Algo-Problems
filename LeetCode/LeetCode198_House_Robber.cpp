/*
1. dfs with memo
2. bottom up
dp[i] = max(nums[i], nums[i] + dp[i+2], nums[i] + dp[i+3])
*/
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums.front();

    for (int i = n - 3; i >= 0; i--) {
      if (i == n - 3)
        nums[i] += nums[i + 2];
      else
        nums[i] += max(nums[i + 2], nums[i + 3]);
    }
    return max(nums[0], nums[1]);
  }
};