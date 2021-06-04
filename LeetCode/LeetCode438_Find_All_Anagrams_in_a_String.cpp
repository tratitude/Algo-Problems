// Time complexity: O(N+M)
// Space complexity: O(1)
// N: s.size()
// M: p.size()
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> need(26, 0), window(26, 0), res;
    int valid = 0, left = 0, right = 0;
    // init need
    for (char c : p) ++need[c - 'a'];

    while (right < s.size()) {
      char r = s[right];
      ++right;
      if (++window[r - 'a'] <= need[r - 'a']) ++valid;

      while (valid == p.size()) {
        char l = s[left];
        ++left;
        if (window[l - 'a'] == need[l - 'a']) {
          --valid;
          // updare res
          if (right - left + 1 == p.size()) res.push_back(left - 1);
        }
        --window[l - 'a'];
      }
    }
    return res;
  }
};