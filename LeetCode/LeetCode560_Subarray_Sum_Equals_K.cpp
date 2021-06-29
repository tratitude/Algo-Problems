// Time complexity: O(N)
// Space complexity: O(N)
// N: size of nums
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int ans = 0;
    unordered_map<int, int> mp;
    // init mp
    mp[0] = 1;

    int sum = 0;
    for (int num : nums) {
      sum += num;
      if (mp.count(sum - k) > 0) {
        ans += mp[sum - k];
      }
      mp[sum] += 1;
    }

    return ans;
  }
};