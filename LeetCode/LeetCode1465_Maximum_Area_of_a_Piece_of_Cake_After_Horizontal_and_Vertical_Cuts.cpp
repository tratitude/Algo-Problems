// Time complexity: O(N*log(N) + M*log(M))
// Space complexity: O(1)
// N: size of horizontalCuts
// M: size of verticalCuts
class Solution {
 public:
  int maxArea(int h, int w, vector<int>& horizontalCuts,
              vector<int>& verticalCuts) {
    int mod = 1e9 + 7;
    horizontalCuts.push_back(0);
    horizontalCuts.push_back(h);
    verticalCuts.push_back(0);
    verticalCuts.push_back(w);
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());

    int maxH = 0, maxV = 0;

    for (int i = 0; i < horizontalCuts.size() - 1; i++) {
      maxH = max(maxH, horizontalCuts[i + 1] - horizontalCuts[i]);
    }
    for (int i = 0; i < verticalCuts.size() - 1; i++) {
      maxV = max(maxV, verticalCuts[i + 1] - verticalCuts[i]);
    }
    return ((long long)maxH * maxV) % mod;
  }
};