// Time complexity: O(N)
// Space complexity: O(1)
// N: size of nums
class Solution {
 public:
  int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    int res = 0, lastInvalid = -1, lastCount = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < left) {
        res += lastCount;
      } else if (nums[i] > right) {
        lastInvalid = i;
        lastCount = 0;
      } else {
        lastCount = i - lastInvalid;
        res += lastCount;
      }
    }
    return res;
  }
};