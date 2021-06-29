// Time complexity: O(N)
// Space complexity: O(1)
// N: size of nums
class Solution {
 public:
  int longestOnes(vector<int>& nums, int k) {
    int ans = 0, zeroCnt = 0, l = 0;

    for (int r = 0; r < nums.size(); r++) {
      if (nums[r] == 0) {
        zeroCnt++;
      }

      while (zeroCnt > k) {
        if (nums[l] == 0) {
          zeroCnt--;
        }
        l++;
      }
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};