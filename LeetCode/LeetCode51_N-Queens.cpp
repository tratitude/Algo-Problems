// Time complexity: O(N^2)
// Space complexity: O(N^2)
// N: n
class Solution {
  vector<vector<string>> res;

 public:
  void backtrack(vector<string>& record, int row) {
    if (row == record.size()) {
      res.push_back(record);
      return;
    }
    for (int col = 0; col < record.size(); col++) {
      if (!isValid(record, row, col)) continue;
      record[row][col] = 'Q';
      backtrack(record, row + 1);
      record[row][col] = '.';
    }
  }
  bool isValid(const vector<string>& record, int row, int col) {
    int N = record.size();
    // check col
    for (int r = 0; r < row; r++) {
      if (record[r][col] == 'Q') return false;
    }
    // check left-upper
    for (int i = 1; i <= row and i <= col; i++) {
      if (record[row - i][col - i] == 'Q') return false;
    }
    // check right-upper
    for (int i = 1; i <= row and i + col < N; i++) {
      if (record[row - i][col + i] == 'Q') return false;
    }
    return true;
  }
  vector<vector<string>> solveNQueens(int n) {
    vector<string> record(n, string(n, '.'));
    backtrack(record, 0);
    return res;
  }
};