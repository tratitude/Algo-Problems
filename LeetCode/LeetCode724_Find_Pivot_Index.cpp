// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int right = accumulate(nums.begin(), nums.end(), 0);
    int left = 0;
    int prev = 0;

    for (int i = 0; i < nums.size(); i++) {
      left += prev;
      right -= nums[i];

      if (left == right) return i;

      prev = nums[i];
    }

    return -1;
  }
};