// Time complexity: O(M*N*K)
// Space complexity: O(M*N)
// M: m
// N: n
// K: maxMove
class Solution {
  const int Mod = 1e9 + 7;
  const vector<int> Dir = {1, 0, -1, 0, 1};
  int Row, Col;

 public:
  int add(int a, int b) { return ((a % Mod) + (b % Mod)) % Mod; }
  bool check(int row, int col) {
    if (row < 0 || row >= Row || col < 0 || col >= Col) return false;
    return true;
  }
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    Row = m, Col = n;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int ans = 0;

    // set start point
    dp[startRow][startColumn] = 1;

    while (maxMove--) {
      // count boundary
      for (int r = 0; r < m; r++) {
        ans = add(ans, dp[r][0]);
        ans = add(ans, dp[r][n - 1]);
      }
      for (int c = 0; c < n; c++) {
        ans = add(ans, dp[0][c]);
        ans = add(ans, dp[m - 1][c]);
      }

      vector<vector<int>> temp(m, vector<int>(n, 0));
      // update position
      for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
          if (dp[r][c] > 0) {
            for (int i = 0; i < Dir.size() - 1; i++) {
              int row = r + Dir[i];
              int col = c + Dir[i + 1];
              if (check(row, col)) {
                temp[row][col] = add(temp[row][col], dp[r][c]);
              }
            }
          }
        }
      }
      // update dp
      dp = temp;
    }

    return ans;
  }
};