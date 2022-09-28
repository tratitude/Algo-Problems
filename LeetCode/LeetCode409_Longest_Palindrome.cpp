// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
 public:
  int longestPalindrome(string s) {
    vector<int> record(256, 0);
    bool hasOdd = false;
    int ans = 0;

    for (auto c : s) {
      ++record[c];
    }

    for (auto num : record) {
      if (!hasOdd) hasOdd = num % 2;
      ans += num / 2;
    }

    return hasOdd ? ans * 2 + 1 : ans * 2;
  }
};