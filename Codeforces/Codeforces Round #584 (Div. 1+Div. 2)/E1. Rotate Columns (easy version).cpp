#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long int lld;
typedef pair<int, int> pii;

int n, m;

void rotateDown(int col, int **mat){
    int last = mat[n - 1][col];
    for(int row=n-1; row>0; row--){
        mat[row][col] = mat[row - 1][col];
    }
    mat[0][col] = last;
}

int rowMax(int **mat)
{
    int num=0;
    for(int i=0; i<n; i++){
        int rowmax = 0;
        for(int j=0; j<m; j++){
            rowmax = mat[i][j] > rowmax ? mat[i][j] : rowmax;
        }
        num += rowmax;
    }
    return num;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(15);
    cout << fixed;

    int t;
    cin >> t;

    while(t--){
        cin >> n >> m;
        int matrix[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> matrix[i][j];
            }
        }
        int max = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

            }
        }
    }

    return 0;
}