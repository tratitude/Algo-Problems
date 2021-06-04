#include <vector>
#include <string>
#include <iostream>
using namespace std;
// Time complexity: O(M+N)
// Space complexity: O(1)
// M: size of s1
// N: size of s2
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    vector<int> window(26, 0), need(26, 0);
    // init need
    for (char c : s1) ++need[c - 'a'];

    int valid = 0, left = 0, right = 0;

    while (right < s2.size()) {
      char r = s2[right];
      ++right;
      if (++window[r - 'a'] <= need[r - 'a']) ++valid;

      while (valid == s1.size()) {
        // check interval size
        if (right - left == s1.size()) return true;

        char l = s2[left];
        ++left;
        if (window[l - 'a'] <= need[l - 'a']) --valid;
        --window[l - 'a'];
      }
    }
    return false;
  }
};
int main()
{
  Solution sol;
  string s1("abcdxabcde"), s2("abcdeabcdx");
  //string s1("abc"), s2("acb");
  cout << sol.checkInclusion(s1, s2);
}
