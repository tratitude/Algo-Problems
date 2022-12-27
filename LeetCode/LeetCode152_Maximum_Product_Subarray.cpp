/*
1. bottom-up
minProduct[i] = min(nums[i], nums[i]*minProduct[i+1], nums[i]*maxProduct[i+1])
maxProduct[i] = max(nums[i], nums[i]*minProduct[i+1], nums[i]*maxProduct[i+1])
*/
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int ans = nums.back(), prevMin = nums.back(), prevMax = nums.back();
    for (int i = nums.size() - 2; i >= 0; i--) {
      if (nums[i] > 0) {
        prevMax = max(nums[i], nums[i] * prevMax);
        prevMin = min(nums[i], nums[i] * prevMin);
      } else {
        int tmp = prevMax;
        prevMax = max(nums[i], nums[i] * prevMin);
        prevMin = min(nums[i], nums[i] * tmp);
      }
      ans = max(ans, prevMax);
    }
    return ans;
  }
};