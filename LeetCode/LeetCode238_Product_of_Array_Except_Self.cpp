// Time complexity: O(N)
// Space complexity: O(1)
/*
1,2,3,4
  1 1 1
    2 2
      3
4 4 4
3 3
2  
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        for (int i = 0, mul = 1; i < n; i++) {
            ans[i] *= mul;
            mul *= nums[i];
        }

        for (int i = n-1, mul = 1; i >= 0; i--) {
            ans[i] *= mul;
            mul *= nums[i];
        }

        return ans;
    }
};
