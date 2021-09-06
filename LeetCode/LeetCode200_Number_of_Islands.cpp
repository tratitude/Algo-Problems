// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
  vector<vector<int>> next = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int yLen = 0;
  int xLen = 0;

 public:
  void dfs(vector<vector<char>>& grid, int y, int x) {
    grid[y][x] = '2';
    for (int i = 0; i < 4; ++i) {
      int nextX = x + next[i][0];
      int nextY = y + next[i][1];
      if (nextX >= 0 && nextX < xLen && nextY >= 0 && nextY < yLen)
        if (grid[nextY][nextX] == '1') dfs(grid, nextY, nextX);
    }
  }
  int numIslands(vector<vector<char>>& grid) {
    yLen = grid.size();
    xLen = grid.back().size();
    int num = 0;

    for (int i = 0; i < yLen; ++i) {
      for (int j = 0; j < xLen; ++j) {
        if (grid[i][j] == '1') {
          dfs(grid, i, j);
          ++num;
        }
      }
    }
    return num;
  }
};

// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
  const vector<int> kDir = {1, 0, -1, 0, 1};
// use macro may be faster in theory
#define inRange(val, low, high) ((low <= val) && (val < high))
 public:
  // val is in [low, high)
  /*
  bool inRange(int val, int low, int high) {
      return low <= val && val < high;
  }
  */
  void dfs(vector<vector<char>>& grid, int row, int col) {
    int M = grid.size(), N = grid.front().size();

    // seen
    grid[row][col] = '0';

    // find next
    for (int i = 0; i < kDir.size() - 1; i++) {
      int next_row = row + kDir[i];
      int next_col = col + kDir[i + 1];
      if (inRange(next_row, 0, M) && inRange(next_col, 0, N) &&
          grid[next_row][next_col] == '1')
        dfs(grid, next_row, next_col);
    }
  }
  int numIslands(vector<vector<char>>& grid) {
    int M = grid.size(), N = grid.front().size(), ans = 0;

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (grid[i][j] == '1') {
          dfs(grid, i, j);
          ++ans;
        }
      }
    }

    return ans;
  }
};