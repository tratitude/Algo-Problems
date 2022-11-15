// Time complexity: O(N)
// Space complexity: O(1)
// N: n
class Solution {
 public:
  int climbStairs(int n) {
    if (n <= 1) return 1;

    int prev1 = 1, prev2 = 1, num = 0;
    for (int i = 2; i <= n; i++) {
      num = prev1 + prev2;
      prev2 = prev1;
      prev1 = num;
    }
    return num;
  }
};
// Time complexity: O(N)
// Space complexity: O(N)
// N: n
/*
dp[i] = dp[i-1] + dp[i-2]
// base case
i= 1 -> 1
i= 2 -> 2
i= 0    -> 0
*/
class Solution {
 public:
  int climbStairs(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
  }
};