// Time complexity: O(N^2)+O(NlogN)
// Space complexity: O(1)
/*
1. Sort than binary search
O(NlogN)+O(N^2)+O(NlogN)

2. Sort than two pointer
O(NlogN)+O(N^2)
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiff = INT_MAX, ans = target;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-2; i++) {
            int front = i + 1, end = nums.size() - 1;
            while (front < end) {
                int curDiff = nums[i] + nums[front] + nums[end] - target;
                if (curDiff == 0) {
                    return target;
                } else if (abs(curDiff) < minDiff) {
                    minDiff = abs(curDiff);
                    ans = curDiff + target;
                }

                if (curDiff > 0) end--;
                else if (curDiff < 0) front++;
            }
        }
        return ans;
    }
};
