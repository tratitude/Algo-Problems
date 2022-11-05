// Time complexity: O(log(N))
// Space complexity: O(1)
// N: size of nums
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (target == nums.front())
            return 0;
        if (target == nums.back())
            return nums.size() - 1;
        if (nums.front() <= nums.back()) {
            return binarySearch(nums, 0, nums.size(), target);
        }

        int max = findMax(nums);
        int ans = -1;
        if (target > nums.front()) {
            ans = binarySearch(nums, 0, max + 1, target);
        } else if (target < nums.back()) {
            ans = binarySearch(nums, max + 1, nums.size(), target);
        }
        return ans;
    }

    int binarySearch(vector<int>& nums, int begin, int end, int target) {
        auto ans = lower_bound(nums.begin() + begin, nums.begin() + end, target);
        if (ans == nums.begin() + end || *ans != target)
            return -1;
        return ans - nums.begin();
    }

    int findMax(vector<int>& nums) {
        int max = 0, left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left)/2;
            if (nums[mid] < nums[max]) {
                right = mid;
            } else {
                left = mid + 1;
                max = mid;
            }
        }
        return max;
    }
};
// Time complexity: O(log(N))
// Space complexity: O(1)
// N: size of nums
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    // binary search in [left, right)
    int left = 0, right = nums.size(), ans = -1;

    while (left < right) {
      int mid = left + (right - left) / 2;

      // [left, mid] must be ascending order
      if (nums[left] < nums[mid]) {
        if (nums[mid] == target) {
          ans = mid;
          break;
        } else if (nums[mid] > target && target >= nums[left]) {
          // find in [left, mid)
          right = mid;
        } else {
          // find in [mid+1, right)
          left = mid + 1;
        }
      }
      // [mid, right] must be acending order
      else {
        if (nums[mid] == target) {
          ans = mid;
          break;
        } else if (nums[mid] < target && target <= nums[right - 1]) {
          // find in [mid+1, right)
          left = mid + 1;
        } else {
          // find in [left, mid)
          right = mid;
        }
      }
    }
    return ans;
  }
};

// Time complexity: O(log(N))
// Space complexity: O(1)
// N: size of nums
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

// sample 0 ms submission
// Time complexity: O(log(N))
// Space complexity: O(1)
// N: size of nums
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