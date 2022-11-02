// Time complexity: O(N^2+NlogN)
// Space complexity: O(N)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] > 0) return {};
        
        unordered_map<int, int> m;
        int n = nums.size();
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i++) m[nums[i]] = i;
        
        for (int i = 0; i < n-2; i++) {
            if (i != 0 && nums[i] == nums[i-1]) continue; // skip the same number
            if (nums[i] > 0) return ans;
            
            for (int j = i + 1; j < n-1; j++) {
                if (j != i+1 && nums[j] == nums[j-1]) continue; // skip the same number
                int target = -nums[i] - nums[j];
                if (m.find(target) != m.end() && m[target] > j)
                    ans.push_back({nums[i], nums[j], target});
            }
        }
        return ans;
    }
};