// Time complexity: O(9^81)
// Space complexity: O(9^81)
/*
1. backtracking

bool bt(i, j)
    // base case
    if (i == 9) return true
    if (j == 9) return bt(i+1, 0)
    if (board[i][j] != '.') return bt(i, j+1)

    for (num = ['1', '9'])
        if (!existed(num, i, j))
            board[i][j] = num
            if (bt(i, j+1)) return true
            board[i][j] = '.'
    
    return false
*/
class Solution {
    vector<vector<bool>> row = vector<vector<bool>> (9, vector<bool>(9, false));
    vector<vector<bool>> col = vector<vector<bool>> (9, vector<bool>(9, false));
    vector<vector<bool>> box = vector<vector<bool>> (9, vector<bool>(9, false));
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    inserted(board[i][j], i, j);
                }
            }
        }
        bt(board, 0, 0);
    }
    bool bt(vector<vector<char>>& board, int i, int j) {
        // base case
        if (i == 9) return true;
        if (j == 9) return bt(board, i+1, 0);
        if (board[i][j] != '.') return bt(board, i, j+1);

        for (char num = '1'; num <= '9'; num++) {
            if (!existed(num, i, j)) {
                board[i][j] = num;
                inserted(num, i, j);
                if (bt(board, i, j+1)) return true;
                board[i][j] = '.';
                erased(num, i, j);
            }
        }

        return false;
    }
    bool existed(char num, int i, int j) {
        int digit = num - '1';
        int boxNum = (i/3)*3 + j/3;
        return row[i][digit] || col[j][digit] || box[boxNum][digit];
    }
    void inserted(char num, int i, int j) {
        int digit = num - '1';
        int boxNum = (i/3)*3 + j/3;
        row[i][digit] = true;
        col[j][digit] = true;
        box[boxNum][digit] = true;
    }
    void erased(char num, int i, int j) {
        int digit = num - '1';
        int boxNum = (i/3)*3 + j/3;
        row[i][digit] = false;
        col[j][digit] = false;
        box[boxNum][digit] = false;
    }
};