#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
// Time complexity: O(N^2)
// Space complexity: O(1)
class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int N = matrix.size();
    if (N == 1) return matrix[0][0];

    for (int i = 0; i < N; ++i) {
      if (i != 0) {
        matrix[i][0] += matrix[i - 1][0];
        matrix[i][N - 1] += matrix[i - 1][N - 2];
        for (int j = 1; j < N - 1; ++j) {
          matrix[i][j] += min(matrix[i - 1][j - 1], matrix[i - 1][j]);
        }
      }

      if (i != N - 1) {
        for (int j = 0; j < N - 1; ++j) {
          matrix[i][j] = min(matrix[i][j], matrix[i][j + 1]);
        }
      }
    }
    return *min_element(matrix.back().begin(), matrix.back().end());
  }
};
// Time complexity: O(N^2)
// Space complexity: O(1)
int minFallingPathSum(vector<vector<int>>& matrix) {
    int matSize = matrix.size();
    for(int r=1; r<matSize; ++r){
        for(int c=0; c<matSize; ++c){
            auto left = matrix[r-1].begin();
            auto right = matrix[r-1].begin()+1;
            if(c == 0){
                left += c;
                right += c+1;
            }
            else if(c == matSize-1){
                left += c-1;
                right += c;
            }
            else{
                left += c-1;
                right += c+1;
            }
            auto min = min_element(left, right);
            matrix[r][c] += *min;
        }
    }
    return *min_element(matrix[matSize-1].begin(), matrix[matSize-1].end());
}

int main()
{
    vector<vector<int>> vec = {{2,1,3},{6,5,4},{7,8,9}};
    cout << minFallingPathSum(vec);
}