// Time complexity: O(N!)
// Space complexity: O(N)
// N: size of nums
class Solution {
  vector<int> record;

 public:
  void backtrack(vector<int>& nums, vector<vector<int>>& res,
                 vector<bool>& seen) {
    if (record.size() == seen.size()) {
      res.push_back(record);
      return;
    }
    for (int i = 0; i < seen.size(); i++) {
      if (!seen[i]) {
        seen[i] = true;
        record.push_back(nums[i]);
        backtrack(nums, res, seen);
        seen[i] = false;
        record.pop_back();
      }
    }
  }
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<bool> seen(nums.size(), false);
    backtrack(nums, res, seen);
    return res;
  }
};