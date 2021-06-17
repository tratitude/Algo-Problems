// Time complexity: O(N^M)
// Space complexity: O(N^M)
// N: length of text1
// M: length of text2
class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int col = text1.size();
    int row = text2.size();
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

    for (int r = 1; r <= row; r++) {
      for (int c = 1; c <= col; c++) {
        if (text1[c - 1] == text2[r - 1]) {
          dp[r][c] = dp[r - 1][c - 1] + 1;
        } else {
          dp[r][c] = max(dp[r - 1][c], dp[r][c - 1]);
        }
      }
    }
    return dp[row][col];
  }
};