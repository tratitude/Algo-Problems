/*
1. combination
C(m+n-2, m-1)
2. backtracking with memo
3. bottom-up
dp[i][j] = dp[i+1][j] + dp[i][j+1]  0<=i<m-1 && 0<=j<n-1
dp[i][j] = 1  i==m-1 && j==n-1
*/
// Time complexity: O(min(N, M))
// Space complexity: O(1)
class Solution {
 public:
  int uniquePaths(int m, int n) {
    long long ans = 1;

    for (int i = m + n - 2, j = 1; j < min(n, m); i--, j++) {
      ans = ans * i / j;
    }
    return ans;
  }
};
// Time complexity: O(N*M)
// Space complexity: O(N*M)
class Solution {
  int M = 0, N = 0;

 public:
  int uniquePaths(int m, int n) {
    M = m;
    N = n;
    vector<vector<int>> memo(m, vector<int>(n, 0));
    return dp(memo, 0, 0);
  }
  int dp(vector<vector<int>>& memo, int i, int j) {
    if (i == M || j == N) return 0;
    if (i == M - 1 && j == N - 1) return 1;
    if (memo[i][j] > 0) return memo[i][j];
    memo[i][j] = dp(memo, i + 1, j) + dp(memo, i, j + 1);
    return memo[i][j];
  }
};
// Time complexity: O(N*M)
// Space complexity: O(N*M)
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = m - 2; i >= 0; i--) {
      for (int j = n - 2; j >= 0; j--) {
        dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
      }
    }
    return dp[0][0];
  }
};