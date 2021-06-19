// Time complexity: O(N*log(N))
// Space complexity: O(1)
// N: size of points
class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(),
         [](auto& l, auto& r) { return l.back() < r.back(); });
    int end = points[0][1];
    int res = 1;
    for (int i = 1; i < points.size(); i++) {
      if (points[i][0] > end) {
        ++res;
        end = points[i][1];
      }
    }
    return res;
  }
};