// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int> temp(nums);
        if (k <= 0) return;

        for (int i = 0; i < k; i++) {
            nums[i] = temp[n-k+i];
        }
        for (int i = k; i < n; i++) {
            nums[i] = temp[i-k];
        }
    }
};

// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (k <= 0) return;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);

        for (int i = 0; i < n; i++) {
            temp[(i+k)%n] = nums[i];
        }
        nums = temp;
    }
};