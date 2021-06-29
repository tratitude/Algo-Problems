// Time complexity: O(N)
// Space complexity: O(1)
// N: size of nums
class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    for (int num : nums) {
      int index = abs(num) - 1;
      if (nums[index] > 0) nums[index] *= -1;
    }
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) ans.push_back(i + 1);
    }
    return ans;
  }
};

// Time complexity: O(N)
// Space complexity: O(N)
// N: size of nums
class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int N = nums.size();
    vector<bool> exist(N + 1, false);
    vector<int> ans;
    for (int num : nums) exist[num] = true;
    for (int i = 1; i <= nums.size(); i++) {
      if (!exist[i]) ans.push_back(i);
    }
    return ans;
  }
};