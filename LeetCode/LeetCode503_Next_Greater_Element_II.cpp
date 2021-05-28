// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int max = nums[0];
    int maxIdx = 0;
    stack<int> s;
    vector<int> res(nums.size());

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > max) {
        max = nums[i];
        maxIdx = i;
      }
    }

    int idx = maxIdx;
    for (int i = 0; i < nums.size(); ++i) {
      while (!s.empty() && nums[idx] >= s.top()) s.pop();

      res[idx] = s.empty() ? -1 : s.top();
      s.push(nums[idx]);

      // update idx
      idx = idx - 1 < 0 ? nums.size() - 1 : idx - 1;
    }

    return res;
  }
};