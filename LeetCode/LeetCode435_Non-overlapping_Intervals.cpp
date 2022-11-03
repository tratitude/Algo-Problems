// Approach: Sorted by end than update the previous end.
// Time complexity: O(N*log(N))
// Space complexity: O(1)
// N: size of intervals
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& lhs, auto& rhs) {
            return lhs.back() < rhs.back();
        });

        int ans = 0, prevEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) {
                ++ans;
            } else {
                prevEnd = intervals[i][1];
            }
        }
        return ans;
    }
};
// Time complexity: O(N*log(N))
// Space complexity: O(1)
// N: size of intervals
class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](auto& l, auto& r) { return l.back() < r.back(); });

    int res = 0;
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
      if (end <= intervals[i][0]) {
        end = intervals[i][1];
      } else {
        ++res;
      }
    }
    return res;
  }
};