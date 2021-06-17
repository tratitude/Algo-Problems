// Brute Force Approach
// Time complexity: O(4^N)
// Space complexity: O(N)
// N: size of matchsticks
class Solution {
  vector<int> len;
  bool found = false;

 public:
  void bruteforce(int index, vector<int>& matchsticks) {
    if (found) return;
    if (index == matchsticks.size()) {
      // check len
      found = true;
      for (int i = 0; i < len.size(); i++) {
        if (len[i] != 0) {
          found = false;
          break;
        }
      }
      return;
    }

    for (int i = 0; i < len.size(); i++) {
      len[i] -= matchsticks[index];
      bruteforce(index + 1, matchsticks);
      len[i] += matchsticks[index];
    }
  }
  bool makesquare(vector<int>& matchsticks) {
    int sum = 0;
    for (int m : matchsticks) {
      sum += m;
    }
    if (sum % 4) return false;

    int avg = sum / 4;
    for (int i = 0; i < 4; i++) len.push_back(avg);

    bruteforce(0, matchsticks);

    return found;
  }
};