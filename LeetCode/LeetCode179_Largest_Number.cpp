// Time complexity: O(NlogN)
// Space complexity: O(N)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto num : nums)
            strs.push_back(to_string(num));

        sort(strs.begin(), strs.end(), [](string& lhs, string& rhs){
            return lhs + rhs > rhs + lhs;
        });

        string ans;
        if (strs[0] == "0")
            return "0";

        for (auto& str : strs) {
            ans += str;
        }

        return ans;
    }
};