// Time complexity: O(N+M)
// Space complexity: O(1)
// N: length of s
// M: length of t
/*
1. sliding window, finding the minimum window [a,b)
- right pointer find the window
- update the ans that is valid
- left pointer shrink the window to invalid state

ADOBECODEBANC
^    ^        <- 1. right pointer find the window
 ^   ^        <- 2. left pointer shrink the window to invalid state
 ^        ^   <- 1.
      ^   ^   <- 2.
      ^     ^ <- 1.
          ^ ^ <- 2.
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0, minLen = INT_MAX, valid = 0;
        int dic[256] = {0}, window[256] = {0};
        pair<int, int> ans;

        // init dic
        for (auto c : t) {
            dic[c]++;
        }

        while (right < s.size()) {
            char r = s[right];
            ++right;
            if (window[r]++ < dic[r]) {
                valid++;
            }

            while (valid == t.size()) {
                // shrink left pointer
                char l = s[left];
                ++left;
                if (--window[l] < dic[l]) {
                    // update ans
                    if (right - left < minLen) {
                        minLen = right - left;
                        ans = {left - 1, right};
                    }
                    valid--;
                }
            }
        }
        return string(s.begin() + ans.first, s.begin() + ans.second);
    }
};
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