// Time complexity: O(logN)
// Space complexity: O(1)
class Solution {
public:
    int firstBadVersion(int n) {
        // [i, j)
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            bool badMid = isBadVersion(mid);
            if (badMid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};