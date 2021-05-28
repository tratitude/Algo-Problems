#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
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