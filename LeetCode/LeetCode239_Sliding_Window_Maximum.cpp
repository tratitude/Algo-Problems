// Time complexity: O(N)
// Space complexity: O(k)
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> res;

    for (int i = 0; i < nums.size(); ++i) {
      // push back to dq
      while (!dq.empty() && nums[i] > dq.back()) dq.pop_back();
      dq.push_back(nums[i]);

      if (i >= k - 1) {
        res.push_back(dq.front());

        // pop front from dq
        if (dq.front() == nums[i - k + 1]) dq.pop_front();
      }
    }
    return res;
  }
};