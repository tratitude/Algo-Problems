// Approach: Record the zero element (i, j) at matrix[0][j] and matrix[i][0]
// Time complexity: O(M*N)
// Space complexity: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool changeCol0 = matrix[0][0] == 0;

        for (int col = 0; col < n; col++) {
            if (matrix[0][col] == 0)
                matrix[0][0] = 0;
        }

        for (int row = 1; row < m; row++) {
            if (matrix[row][0] == 0)
                changeCol0 = true;
            for (int col = 1; col < n; col++) {
                if (matrix[row][col] == 0)
                    matrix[0][col] = matrix[row][0] = 0;
            }
        }

        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {
                if (matrix[0][col] == 0 || matrix[row][0] == 0)
                    matrix[row][col] = 0;
            }
            if (changeCol0)
                matrix[row][0] = 0;
        }

        if (matrix[0][0] == 0) {
            for (int col = 1; col < n; col++)
                matrix[0][col] = 0;
        }

        if (changeCol0)
            matrix[0][0] = 0;
    }
};
// Time complexity: O(M*N)
// Space complexity: O(M+N)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (matrix[r][c] == 0) {
                    row[r] = col[c] = true;
                }
            }
        }

        for (int r = 0; r < m; r++) {
            bool changeRow = row[r];
            for (int c = 0; c < n; c++) {
                if (changeRow || col[c]) {
                    matrix[r][c] = 0;
                }
            }
        }
    }
};