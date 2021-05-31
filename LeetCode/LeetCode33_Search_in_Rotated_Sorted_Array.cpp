#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// Time complexity: O(log(n))
// Space complexity: O(1)
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int pivot = nums[0];
    int res = 0;

    // specail case
    if (pivot == target) return 0;

    // find unrotated nums[0] or nums[n-1] in [0, n-1]
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (pivot < nums[mid])
        l = mid + 1;
      else if (pivot > nums[mid])
        r = mid - 1;
      else if (pivot == nums[mid])  // go right because pivot is in left
        l = mid + 1;
    }

    // just one sub-array
    if (r == -1) {
      auto it = equal_range(nums.begin(), nums.end(), target);
      if(it.first != nums.end() && *(it.first) == target)
        res = it.first - nums.begin();
      else
       res = -1;
    } else {
      auto itL = equal_range(nums.begin(), nums.begin() + r + 1, target);
      if (itL.first != nums.end() && *(itL.first) == target) {
        res = itL.first - nums.begin();
      } else {
        auto itR = equal_range(nums.begin() + l, nums.end(), target);
        if (itR.first != nums.end() && *(itR.first) == target)
          res = itR.first - nums.begin();
        else
          res = -1;
      }
    }
    return res;
  }
};

/*
// sample 0 ms submission
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int prev = 0;
    int search = -1;
    int latter = nums.size() - 1;
    while (prev <= latter) {
      int mid = (prev + latter) / 2;
      if (target == nums[mid]) {                            // found target
        search = mid;
        return search;
      } else if (nums[mid] >= nums[prev]) {                 // [pre, mid] is in same sub-array
        if (target < nums[mid] && target >= nums[prev])       // target is in [pre, mid), find left
          latter = mid - 1;
        else {
          prev = mid + 1;                                     // target is in (mid, latter], find right
        }
      } else {                                              // [pre, mid] isn't in same sub-array, imply that (mid, latter] is in same sub-array
        if (target > nums[mid] && target <= nums[latter]) {   // target is in (mid, latter], find right
          prev = mid + 1;
        } else {                                              // target is in [pre, mid), find left
          latter = mid - 1;
        }
      }
    }
    return -1;
  }
};
*/
int main()
{
  Solution sol;
  vector<int> vec = { 4, 5, 6, 0, 1, 2 , 3};
  int target = 4;
  //vector<int> vec = {3, 1};
  //int target = 1;
  cout << sol.search(vec, target) << "\n";
}