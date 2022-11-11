// Time complexity: O(N)
// Space complexity: O(1)
/*
1. put {1,2,3...} into {nums[0], nums[1],nums[2]...}
[3,1,2]
2,1,3 i=0, nums[i] > i+1 && nums[i] <= n -> swap(nums[i], nums[nums[i]-1])
1,2,3 i=0, nums[i] > i+1 && nums[i] <= n -> swap(nums[i], nums[nums[i]-1])
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (((nums[i] > i+1 && nums[i] <= n) || (nums[i] < i+1 && nums[i] > 0)) && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};