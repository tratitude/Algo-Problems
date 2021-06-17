// Time complexity: O(N*log(N))
// Space complexity: O(N)
// N: number of envelopes
class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), [](auto& l, auto& r) {
      return l[0] < r[0] or (l[0] == r[0] and l[1] > r[1]);
    });
    vector<int> lis;
    for (auto& env : envelopes) {
      auto it = lower_bound(lis.begin(), lis.end(), env[1]);
      if (it == lis.end()) {
        lis.push_back(env[1]);
      } else {
        *it = env[1];
      }
    }
    return lis.size();
  }
};