// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
  using PII = pair<int, int>;

 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size());
    // {temperature, index}
    stack<PII> s;

    for (int i = temperatures.size() - 1; i >= 0; --i) {
      while (!s.empty() && temperatures[i] >= s.top().first) s.pop();

      res[i] = s.empty() ? 0 : s.top().second - i;

      s.push({temperatures[i], i});
    }
    return res;
  }
};