// Time complexity: O(M+N)
// Space complexity: O(1)
class Solution {
 public:
  bool isSubsequence(string s, string t) {
    // edge case
    if (s.size() == 0) return true;

    int idxs = 0;
    for (int idxt = 0; idxt < t.size(); idxt++) {
      if (s[idxs] == t[idxt]) ++idxs;
      if (idxs == s.size()) return true;
    }
    return false;
  }
};