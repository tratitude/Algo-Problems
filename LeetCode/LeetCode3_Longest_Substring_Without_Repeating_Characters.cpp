// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    vector<int> window(256, 0);
    int left = 0, right = 0;
    bool rep = false;
    int res = 0;

    while (right < s.size()) {
      char r = s[right];
      ++right;
      if (++window[r] == 2) rep = true;

      while (rep) {
        char l = s[left];
        ++left;
        if (--window[l] == 1) rep = false;
      }

      // update res
      res = max(res, right - left);
    }
    return res;
  }
};