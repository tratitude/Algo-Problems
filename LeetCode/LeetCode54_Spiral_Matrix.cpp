// Time complexity: O(M*N)
// Space complexity: O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int top = 0, bottom = row - 1, left = 0, right = col - 1, dir = 0;
        vector<int> ans;

        while (ans.size() < row * col) {
            switch (dir) {
                case 0: // top row
                    for (int i = left; i <= right; i++)
                        ans.push_back(matrix[top][i]);
                    ++top;
                    dir = 1;
                    break;
                case 1: // right col
                    for (int j = top; j <= bottom; j++)
                        ans.push_back(matrix[j][right]);
                    --right;
                    dir = 2;
                    break;
                case 2: // bottom row
                    for (int i = right; i >= left; i--)
                        ans.push_back(matrix[bottom][i]);
                    --bottom;
                    dir = 3;
                    break;
                case 3: // left col
                    for (int j = bottom; j >= top; j--)
                        ans.push_back(matrix[j][left]);
                    ++left;
                    dir = 0;
                    break;
            }
        }
        return ans;
    }
};