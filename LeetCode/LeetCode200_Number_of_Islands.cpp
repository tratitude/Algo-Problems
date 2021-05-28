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