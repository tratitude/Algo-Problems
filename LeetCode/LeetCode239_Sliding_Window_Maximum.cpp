// Approach: Mono-queue
// - Remove the elements from rhs of the window that not greater than nums[i]
// - Add index i rhs of the window
// - Remove the outdated indices lhs i.e. window[x] <= i-k
// - Add window[0] into ans
// Time complexity: O(N)
// Space complexity: O(k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            while (window.size() > 0 && nums[window.back()] <= nums[i])
                window.pop_back();
            window.push_back(i);
            if (window.size() > 0 && window.front() <= i - k)
                window.pop_front();
            if (i >= k-1)
                ans.push_back(nums[window.front()]);
        }
        return ans;
    }
};
// Approach: Heap
// - Add nums[i] to window
// - Remove leftmost num from window
// - Find largest num
// Time complexity: O(N*logN)
// Space complexity: O(k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            window.insert(nums[i]);
            if (window.size() > k)
                window.erase(window.lower_bound(nums[i-k]));
            if (window.size() == k)
                ans.push_back(*window.rbegin());
        }
        return ans;
    }
};
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