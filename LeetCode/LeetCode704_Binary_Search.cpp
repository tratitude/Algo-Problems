// Time complexity: O(logN)
// Space complexity: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // [i, j)
        int left = 0, right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            int num = nums[mid];
            if (num == target) {
                return mid;
            } else if (num > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
// Time complexity: O(logN)
// Space complexity: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto ans = lower_bound(nums.begin(), nums.end(), target);
        if (ans == nums.end() || *ans != target)
            return -1;
        return static_cast<int>(ans - nums.begin());
    }
};