// binary tree postorder traverse approach
// Time complexity: O(N*2^N)
// Space complexity: O(N*2^N)
// N: size of nums
class Solution {
  vector<vector<int>> ans;

 public:
  void traverse(int index, bool isContain, vector<int>& nums,
                vector<int> temp) {
    if (isContain) temp.push_back(nums[index]);

    if (index + 1 == nums.size()) {
      ans.push_back(temp);
      return;
    }
    traverse(index + 1, true, nums, temp);
    traverse(index + 1, false, nums, temp);
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    traverse(0, true, nums, {});
    traverse(0, false, nums, {});

    return ans;
  }
};

// Backtrack Approach
// Time complexity: O(N*2^N)
// Space complexity: O(N)
// N: size of nums
class Solution {
  vector<vector<int>> ans;
  vector<int> temp;

 public:
  void backtrack(int target, int start, vector<int>& nums) {
    if (target == temp.size()) {
      ans.push_back(temp);
      return;
    }

    for (int i = start; i < nums.size(); i++) {
      temp.push_back(nums[i]);
      backtrack(target, i + 1, nums);
      temp.pop_back();
    }
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    for (int t = 0; t <= nums.size(); t++) {
      backtrack(t, 0, nums);
    }

    return ans;
  }
};