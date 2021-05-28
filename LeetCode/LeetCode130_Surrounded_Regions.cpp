// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
  using PII = pair<int, int>;
  int xLen = 0;
  int yLen = 0;
  vector<PII> next = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

 public:
  void solve(vector<vector<char>>& board) {
    xLen = board.begin()->size();
    yLen = board.size();
    vector<PII> border;

    for (int i = 0; i < xLen; ++i) {
      if (board[0][i] == 'O') {
        board[0][i] = '#';
        border.push_back(make_pair(0, i));
      }
      if (board[yLen - 1][i] == 'O') {
        board[yLen - 1][i] = '#';
        border.push_back(make_pair(yLen - 1, i));
      }
    }
    for (int j = 0; j < yLen; ++j) {
      if (board[j][0] == 'O') {
        board[j][0] = '#';
        border.push_back(make_pair(j, 0));
      }
      if (board[j][xLen - 1] == 'O') {
        board[j][xLen - 1] = '#';
        border.push_back(make_pair(j, xLen - 1));
      }
    }

    for (auto& p : border) dfs(board, p);

    for (int j = 0; j < yLen; ++j) {
      for (int i = 0; i < xLen; ++i) {
        if (board[j][i] == 'O')
          board[j][i] = 'X';
        else if (board[j][i] == '#')
          board[j][i] = 'O';
      }
    }
  }
  void dfs(vector<vector<char>>& board, PII p) {
    if (board[p.first][p.second] == 'X') return;
    for (int i = 0; i < 4; ++i) {
      PII np = {next[i].first + p.first, next[i].second + p.second};
      if (np.first >= 0 && np.first < yLen && np.second >= 0 &&
          np.second < xLen && board[np.first][np.second] == 'O') {
        board[np.first][np.second] = '#';
        dfs(board, np);
      }
    }
  }
};