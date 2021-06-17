#include <vector>
#include <iostream>
#include <string>
using namespace std;

// 2D DP
// Time complexity: O(N^2), Space complexity: O(N^2)
class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    int N = s.size();
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i) dp[i][i] = 1;

    for (int i = N - 2; i >= 0; --i) {
      for (int j = i + 1; j < N; ++j) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        } else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[0][N - 1];
  }
};
// 1D DP
// Time complexity: O(N^2), Space complexity: O(N)
int longestPalindromeSubseq(string s) {
    int n = s.size();
    // base case：一维 dp 数组全部初始化为 0
    vector<int> dp(n, 1);

    for (int i = n - 2; i >= 0; i--) {
        int pre = 0;
        for (int j = i + 1; j < n; j++) {
            int temp = dp[j];
            // 状态转移方程
            if (s[i] == s[j])
                dp[j] = pre + 2;
            else
                dp[j] = max(dp[j], dp[j - 1]);  // Why dp[j-1] is working?
            pre = temp;
        }
    }
    return dp[n - 1];
}

int main()
{
    cout << longestPalindromeSubseq("bbcbab");
}