#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;
// Time complexity: O(S+T)
// Space complexity: O(T)
// S: size of string s
// T: size of stirng t
/*
class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    // init need
    for (char c : t) ++need[c];

    int valid = 0, left = 0, right = 0;
    int start = 0, len = INT_MAX;

    while (right < s.size()) {
      // window right expand
      char r = s[right];
      ++right;
      if (need.count(r) > 0) {
        ++window[r];
        if (window[r] == need[r]) {
          // update valid
          ++valid;
        }
      }

      // window right shrink
      while (valid == need.size()) {
        // update start, len
        if (right - left < len) {
          len = right - left;
          start = left;
        }
        char l = s[left];
        ++left;
        if (need.count(l) > 0) {
          if (window[l] == need[l]) --valid;
          --window[l];
        }
      }
    }

    return len == INT_MAX ? "" : s.substr(start, len);
  }
};
*/
// Time and Space complexity same as above but faster
// Use vector instead of unordered_map
class Solution {
 public:
  string minWindow(string s, string t) {
    vector<int> need(256, 0);
    vector<int> window(256, 0);
    // init need
    for (char c : t) ++need[c];

    int valid = 0, left = 0, right = 0;
    int start = 0, len = INT_MAX;

    while (right < s.size()) {
      // window right expand
      char r = s[right];
      ++right;
      if (need[r] > 0) {
        ++window[r];
        if (window[r] <= need[r]) {
          // update valid
          ++valid;
        }
      }

      // window right shrink
      while (valid == t.size()) {
        // update start, len
        if (right - left < len) {
          len = right - left;
          start = left;
        }
        char l = s[left];
        ++left;
        if (need[l] > 0) {
          if (window[l] <= need[l]) --valid;
          --window[l];
        }
      }
    }

    return len == INT_MAX ? "" : s.substr(start, len);
  }
};
int main()
{
  Solution sol;
  string s("ADOBECODEBANC"), t("ABC");
  cout << sol.minWindow(s, t) << "\n";
}