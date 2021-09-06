// Time complexity: O(N^2)
// Space complexity: O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        
        for(int r = 0; r < N; r++) {
            for(int c = r; c < N; c++) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }
        
        for(int r = 0; r < N; r++) {
            for(int c = 0; c < N / 2; c++) {
                swap(matrix[r][c], matrix[r][N - 1 - c]);
            }
        }
    }
};

/*
  0  1  2 
0 

1

2

center = (1, 1) * 2 = (2, 2)

  0  1  2  3
0 

1

2

3

center = (2.5, 2.5) * 2 = (5, 5)


Approach: Rotation matrix transform

原座標 (x, y) * 2 -> 轉換後座標 (2x, 2y)

(n, n) // 轉換後的中心點

M * (2x - n, 2y - n) + (n, n) = (2x', 2y')  // M 旋轉矩陣 = | 0 -1 |
                                            //             | 1  0 |

(2x', 2y') / 2 = (x', y') = (-y + n, x) // 旋轉後的原座標

也就是原座標 (x, y) 先 x y 交換 -> (y, x)

每個 row 每個元素再頭尾交換 -> (n - y, x)

*/