// Time complexity: O(N)
// Space complexity: O(N^2)
// N: numRows
class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for (int i = 1; i <= numRows; i++) {
      vector<int> v(i, 1);
      for (int j = 2; j < i; j++) {
        v[j - 1] = ans[i - 2][j - 2] + ans[i - 2][j - 1];
      }
      ans.push_back(v);
    }
    return ans;
  }
};