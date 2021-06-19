// Time complexity: O(N)
// Space complexity: O(1)
// N: size of nums
class Solution {
 public:
  int jump(vector<int>& nums) {
    int res = 0, end = 0, farthest = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      farthest = max(farthest, i + nums[i]);
      if (end == i) {
        end = farthest;
        ++res;
      }
    }
    return res;
  }
};