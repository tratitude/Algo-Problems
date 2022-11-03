// Time complexity: O(M*N)
// Space complexity: O(M*N)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') continue;
                int digit = board[i][j] - '1';

                if (row[i][digit]) return false;
                row[i][digit] = true;
                if (col[j][digit]) return false;
                col[j][digit] = true;

                int boxNum = toBoxNum(i, j);
                if (box[boxNum][digit]) return false;
                box[boxNum][digit] = true;
            }
        }
        return true;
    }
    int toBoxNum(int i, int j) {
        return (i/3)*3 + j/3;
    }
};