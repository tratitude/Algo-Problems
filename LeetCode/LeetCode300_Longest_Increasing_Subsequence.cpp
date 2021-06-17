#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// Binary Search Approach
// Time complexity: O(N*log(N))
// Space complexity: O(N)
// N: size of nums
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> v;
    for (int n : nums) {
      auto it = lower_bound(v.begin(), v.end(), n);
      if (it == v.end()) {
        v.push_back(n);
      } else {
        *it = n;
      }
    }
    return v.size();
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {0, 1, 0, 3, 2, 3};
  cout << sol.lengthOfLIS(nums);
}
/*
// DP Approach
// Time complexity: O(N^2)
// Space complexity: O(N)
// N: size of nums
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int N = nums.size();
    vector<int> dp(N, 1);

    for (int i = 1; i < N; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};

// Brute Force Approach
// Time complexity: O(N!)
// Space complexity: O(N)
// N: size of nums
class Solution {
 public:
  int bruteforce(int idx, int seq, vector<int>& nums) {
    if (!idx) return seq;
    int maxSeq = seq;
    for (int i = idx - 1; i >= 0; i--) {
      if (nums[i] < nums[idx]) {
        maxSeq = max(maxSeq, bruteforce(i, seq + 1, nums));
      }
    }
    return maxSeq;
  }
  int lengthOfLIS(vector<int>& nums) {
    return bruteforce(nums.size() - 1, 1, nums);
  }
};
*/