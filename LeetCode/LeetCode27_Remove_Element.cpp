// Time complexity: O(N)
// Space complexity: O(1)
// N: size of nums
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    if (nums.size() == 0) return 0;
    int slow = 0;
    while (slow < nums.size()) {
      if (nums[slow] == val) {
        int fast = slow + 1;
        while (fast < nums.size() && nums[fast] == val) {
          ++fast;
        }
        if (fast < nums.size()) {
          swap(nums[slow], nums[fast]);
        }
      }
      ++slow;
    }
    int res = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == val) {
        res = i;
        break;
      }
    }
    return res;
  }
};