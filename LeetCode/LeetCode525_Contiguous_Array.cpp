// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // counter -> index
        // same counter value means continuous target found
        unordered_map<int, int> mp = {{0, -1}};
        int counter = 0, ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            counter += nums[i] == 0 ? -1 : 1;
            if (mp.count(counter) > 0) {
                ans = max(ans, i - mp[counter]);
            } else {
                mp[counter] = i;
            }
        }
        return ans;
    }
};