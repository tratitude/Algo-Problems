// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int front = 0, end = nums.size() - 1;
        vector<int> ans;

        while (front <= end) {
            if (abs(nums[front]) > abs(nums[end])) {
                ans.push_back(pow(nums[front], 2));
                front++;
            } else {
                ans.push_back(pow(nums[end], 2));
                end--;
            }
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int front = 0, end = n - 1, i = n - 1;
        vector<int> ans(n);

        while (i >= 0) {
            if (abs(nums[front]) > abs(nums[end])) {
                ans[i--] = pow(nums[front], 2);
                front++;
            } else {
                ans[i--] = pow(nums[end], 2);
                end--;
            }
        }

        return ans;
    }
};