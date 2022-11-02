// Two pointer approach: 高度較小的pointer往內找比較高的，直到碰到邊界或left pointer大於等於right pointer
// Time complexity: O(N)
// Space complexity: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lptr = 0, rptr = height.size() - 1, ans = 0;

        while (lptr < rptr) {
            int area = (rptr - lptr) * min(height[lptr], height[rptr]);
            ans = max(ans, area);
            if (height[lptr] > height[rptr])
                rptr--;
            else
                lptr++;
        }

        return ans;
    }
};