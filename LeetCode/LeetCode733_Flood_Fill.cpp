// Time complexity: O(M*N)
// Space complexity: O(M*N)
class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int color) {
    int row = image.size(), col = image.front().size(),
        orgColor = image[sr][sc];
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    queue<pair<int, int>> q;
    int dim[5] = {1, 0, -1, 0, 1};

    q.push({sr, sc});

    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();
      image[r][c] = color;
      visited[r][c] = true;

      for (int i = 0; i < 4; i++) {
        int nextR = r + dim[i], nextC = c + dim[i + 1];
        if (nextR >= 0 && nextR < row && nextC >= 0 && nextC < col)
          if (image[nextR][nextC] == orgColor && !visited[nextR][nextC])
            q.push({nextR, nextC});
      }
    }
    return image;
  }
};