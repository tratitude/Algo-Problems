// Time complexity: O(M*N)
// Space complexity: O(M*N)
// M: size of s1
// N: size of s2
class Solution {
  string g1, g2, g3;

 public:
  bool bf(int f1, int f2, int f3, vector<vector<int>>& memo) {
    if (f1 == g1.size()) return g2.substr(f2).compare(g3.substr(f3)) == 0;
    if (f2 == g2.size()) return g1.substr(f1).compare(g3.substr(f3)) == 0;

    // check memo
    if (memo[f1][f2] >= 0) return memo[f1][f2] == 1 ? true : false;

    bool res = false;
    if (g1[f1] == g3[f3]) res |= bf(f1 + 1, f2, f3 + 1, memo);
    if (g2[f2] == g3[f3]) res |= bf(f1, f2 + 1, f3 + 1, memo);

    // update memo
    memo[f1][f2] = res ? 1 : 0;

    return res;
  }
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;

    g1 = s1;
    g2 = s2;
    g3 = s3;
    string res;
    vector<vector<int>> memo(s1.size(), vector<int>(s2.size(), -1));
    return bf(0, 0, 0, memo);
  }
};