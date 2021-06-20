// Time complexity: O(32)
// Space complexity: O(1)
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int size = sizeof(n) * 8;
    int ans = 0;
    for (int i = 0; i < size; i++) {
      if (n & 1) ++ans;
      n >>= 1;
    }
    return ans;
  }
};