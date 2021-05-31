#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// Time complexity: O(N*log(S))
// N: number of nums
// S: summation of nums
class Solution {
 public:
  int split(vector<int>& nums, int sum) {
    int count = 0;
    int res = 1;

    for (int i = 0; i < nums.size(); ++i) {
      if (count + nums[i] > sum) {
        ++res;
        count = nums[i];
      } else {
        count += nums[i];
      }
    }

    return res;
  }
  int splitArray(vector<int>& nums, int m) {
    int lo = *max_element(nums.begin(), nums.end());
    int hi = 0;  // summation of nums
    for (int num : nums) hi += num;

    // find a minimum sum such that split number equal to m
    // lower bound in [lo, hi+1)
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      int sp = split(nums, mid);
      // mid go up than sp go down
      if (sp > m)
        lo = mid + 1;
      else if(sp < m)
        hi = mid;
      else
        hi = mid;
    }

    return lo;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {7, 2, 5, 10, 8};
  int m = 1;
  cout << sol.splitArray(nums, m);
}