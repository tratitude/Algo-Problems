// Time complexity: O(M+N)
// Space complexity: O(N)
// N: nums1.size()
// M: nums2.size()
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res(nums1.size());
    // nums2[i] -> next greater num
    unordered_map<int, int> next;
    stack<int> s;

    for (auto it = nums2.rbegin(); it != nums2.rend(); ++it) {
      while (!s.empty() && s.top() < *it) s.pop();

      next[*it] = s.empty() ? -1 : s.top();

      s.push(*it);
    }

    for (int i = 0; i < nums1.size(); ++i) {
      res[i] = next[nums1[i]];
    }

    return res;
  }
};