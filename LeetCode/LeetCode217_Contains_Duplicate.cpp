class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> record = {nums[0]};

    for (int i = 1; i < nums.size(); i++) {
      if (record.count(nums[i])) return true;

      record.insert(nums[i]);
    }

    return false;
  }
};