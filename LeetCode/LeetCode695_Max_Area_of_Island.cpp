// Time complexity: O(M*N)
// Space complexity: O(M*N)
class Solution {
  vector<int> dir = {1, 0, -1, 0, 1};
  int yLen = 0;
  int xLen = 0;

 public:
  int dfs(vector<vector<int>>& grid, int x, int y) {
    grid[y][x] = 0;
    int res = 1;
    for (int i = 0; i < dir.size() - 1; ++i) {
      int nx = x + dir[i];
      int ny = y + dir[i + 1];
      if (nx >= 0 && nx < xLen && ny >= 0 && ny < yLen && grid[ny][nx] == 1)
        res += dfs(grid, nx, ny);
    }
    return res;
  }
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    yLen = grid.size();
    xLen = grid.back().size();
    int res = 0;

    for (int y = 0; y < yLen; ++y) {
      for (int x = 0; x < xLen; ++x) {
        if (grid[y][x] == 1) res = max(res, dfs(grid, x, y));
      }
    }
    return res;
  }
};