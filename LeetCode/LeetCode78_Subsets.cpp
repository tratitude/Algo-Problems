// Time complexity: O(2^N)
// Space complexity: O(N)
// N: size of nums
class Solution {
  vector<vector<int>> res;
  vector<int> record;

 public:
  void backtrack(int target, int start, vector<bool>& seen, vector<int>& nums) {
    if (target < 0) {
      res.push_back(record);
      return;
    }
    for (int i = start; i < nums.size(); i++) {
      if (!seen[i]) {
        seen[i] = true;
        record.push_back(nums[i]);

        backtrack(target - 1, i, seen, nums);

        seen[i] = false;
        record.pop_back();
      }
    }
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    int N = nums.size();
    // insert empty set
    res.push_back(record);
    for (int i = 0; i < N; i++) {
      vector<bool> seen(N, false);
      backtrack(i, 0, seen, nums);
    }
    return res;
  }
};