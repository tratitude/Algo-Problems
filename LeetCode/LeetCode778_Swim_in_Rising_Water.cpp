#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    priority_queue<pair<int, int>> q;
    q.push({-grid[0][0], 0 * n + 0});
    vector<int> seen(n * n, 0);
    vector<int> dirs{-1, 0, 1, 0, -1};

    seen[0 * n + 0] = 1;
    while (!q.empty()) {
      auto node = q.top();
      q.pop();
      int t = -node.first;
      int x = node.second % n;
      int y = node.second / n;
      if (x == n - 1 && y == n - 1) 
        return t;
      for (int i = 0; i < 4; i++) {
        int tx = x + dirs[i];
        int ty = y + dirs[i + 1];
        if (tx < 0 || ty < 0 || tx >= n || ty >= n || seen[ty * n + tx])
          continue;
        seen[ty * n + tx] = 1;
        q.push({-max(t, grid[ty][tx]), ty * n + tx});
      }
    }

    return -1;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> grid = {
    {0, 1, 2, 3, 4},
    {24, 23, 22, 21, 5},
    {12, 13, 14, 15, 16},
    {11, 17, 18, 19, 20},
    {10, 9, 8, 7, 6}
  };
  cout << sol.swimInWater(grid);
}