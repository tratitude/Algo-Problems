// Time complexity: O(logN)
// Space complexity: O(1)
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] > nums[right]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return nums[left];
  }
};
// Time complexity: O(logN)
// Space complexity: O(1)
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1, ans = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[left] > nums[right]) {
        if (nums[mid] >= nums[left])
          left = mid + 1;
        else
          right = mid;
      } else {
        ans = nums[left];
        return ans;
      }
    }
    return ans;
  }
};