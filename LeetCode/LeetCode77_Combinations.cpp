// Time complexity: O(N!)
// Space complexity: O(N)
// N: n
class Solution {
  vector<vector<int>> res;
  vector<int> record;

 public:
  void backtrack(int target, int start, vector<bool>& seen) {
    if (!target) {
      res.push_back(record);
      return;
    }
    for (int i = start; i < seen.size(); i++) {
      if (!seen[i]) {
        seen[i] = true;
        record.push_back(i + 1);

        backtrack(target - 1, i, seen);

        seen[i] = false;
        record.pop_back();
      }
    }
  }
  vector<vector<int>> combine(int n, int k) {
    vector<bool> seen(n, false);
    backtrack(k, 0, seen);

    return res;
  }
};