// Time complexity: O(log(M*N))
// Space complexity: O(1)
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (target < matrix[0][0] || target > matrix.back().back()) return false;

    int row = matrix.size(), col = matrix[0].size();
    int left = 0, right = row;
    while (left < right) {
      int mid = left + (right - left) / 2;
      int midVal = matrix[mid].back();
      if (target < midVal) {
        right = mid;
      } else if (target > midVal) {
        left = mid + 1;
      } else {
        return true;
      }
    }

    int r = left;
    left = 0, right = col;
    while (left < right) {
      int mid = left + (right - left) / 2;
      int midVal = matrix[r][mid];
      if (target < midVal) {
        right = mid;
      } else if (target > midVal) {
        left = mid + 1;
      } else {
        return true;
      }
    }
    return false;
  }
};
// Time complexity: O(log(M*N))
// Space complexity: O(1)
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();
    int left = 0, right = row * col;
    while (left < right) {
      int mid = left + (right - left) / 2;
      int midVal = matrix[mid / col][mid % col];
      if (target < midVal) {
        right = mid;
      } else if (target > midVal) {
        left = mid + 1;
      } else {
        return true;
      }
    }
    return false;
  }
};