/*

toggle even time -> on
       sigle     -> off

single iff it's a square number

example 1:

1  2    3    4
1  1,2  1,3  1,2,4
on off  off  on

*/
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
 public:
  int bulbSwitch(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int sq = sqrt(i);
      if (sq * sq == i) ans++;
    }

    return ans;
  }
};

// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
 public:
  int bulbSwitch(int n) { return sqrt(n); }
};