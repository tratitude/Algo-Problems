// Time complexity: O(NlogN)
// Space complexity: O(N)
class Solution {
    // Assume a[0] < b[0]
    bool isOverlap(vector<int>& a, vector<int>& b) {
        return a[1] >= b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> ans;
        vector<int> merged = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (isOverlap(merged, intervals[i])) {
                merged[0] = min(merged[0], intervals[i][0]);
                merged[1] = max(merged[1], intervals[i][1]);
            } else {
                ans.push_back(merged);
                merged = intervals[i];
            }
        }
        ans.push_back(merged);
        return ans;
    }
};