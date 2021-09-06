// Time complexity: O(N!)
// Space complexity: O(N)
// N: n
class Solution {
  int N;
  vector<vector<int>> ans;
  vector<int> temp;

 public:
  void backtrack(int start, int target) {
    if (target == 0) {
      ans.push_back(temp);
      return;
    }

    for (int i = start; i <= N; i++) {
      temp.push_back(i);
      backtrack(i + 1, target - 1);
      temp.pop_back();
    }
  }
  vector<vector<int>> combine(int n, int k) {
    N = n;
    backtrack(1, k);

    return ans;
  }
};