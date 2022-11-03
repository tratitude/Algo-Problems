// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string cmp = *min_element(strs.begin(), strs.end());

        for (int i = 0; i < cmp.size(); i++) {
            for (auto& str : strs) {
                // cout << *(str.begin() + i) << " " << cmp[i] << endl;
                if (*(str.begin() + i) != cmp[i]) {
                    return cmp.substr(0, i);
                }
            }
        }

        // cmp is common prefix
        return cmp;
    }
};