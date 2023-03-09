// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
 public:
  int maxArea(vector<int>& height) {
    deque<int> leftIdx, rightIdx;

    leftIdx.push_back(0);
    rightIdx.push_back(height.size() - 1);

    for (int i = 1; i < height.size(); i++) {
      if (height[i] > height[leftIdx.back()]) leftIdx.push_back(i);
    }
    for (int i = height.size() - 2; i >= 0; i--) {
      if (height[i] > height[rightIdx.back()]) rightIdx.push_back(i);
    }

    int left = leftIdx.front();
    leftIdx.pop_front();
    int right = rightIdx.front();
    rightIdx.pop_front();
    int ans = area(height, left, right);

    while (!leftIdx.empty() || !rightIdx.empty()) {
      if (height[left] <= height[right] && !leftIdx.empty()) {
        left = leftIdx.front();
        leftIdx.pop_front();
      } else if (height[right] <= height[left] && !rightIdx.empty()) {
        right = rightIdx.front();
        rightIdx.pop_front();
      }
      ans = max(ans, area(height, left, right));
    }
    return ans;
  }
  int area(vector<int>& height, int left, int right) {
    return (right - left) * min(height[left], height[right]);
  }
};
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