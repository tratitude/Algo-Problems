// Time complexity: O(n), Space complexity: O(n)
class Solution {
 public:
  int numTrees(int n) {
    vector<int> num(n + 1, 1);

    for (int i = 2; i <= n; ++i) {
      int result = 0;
      for (int j = 0; j < i; ++j) {
        result += num[j] * num[i - 1 - j];
      }
      num[i] = result;
    }

    return num[n];
  }
};