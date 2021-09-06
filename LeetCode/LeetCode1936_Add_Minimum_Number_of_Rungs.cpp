// Greedy approach: Always go the next highest rung whether or not it's in rungs.
// Time complexity: O(N)
// Space complexity: O(1)
// N: size of rungs
class Solution {
  using LL = long long;

 public:
  int addRungs(vector<int>& rungs, int dist) {
    LL cur = 0, ans = 0;
    for (const auto& rung : rungs) {
      if (cur + dist < rung) {
        ans += ceil((double)(rung - cur) / dist) - 1;
      }
      cur = rung;
    }
    return ans;
  }
};