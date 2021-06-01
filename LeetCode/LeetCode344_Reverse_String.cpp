// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
 public:
  void reverseString(vector<char>& s) {
    int n = (s.size() - 1) / 2;
    int end = s.size() - 1;

    for (int i = 0; i <= n; ++i) {
      swap(s[i], s[end - i]);
    }
  }
};