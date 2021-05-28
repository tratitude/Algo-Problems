#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long int lld;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(15);
    cout << fixed;
    
    int input;
    cin >> input;

    for(int i=0; i<input; i++){
        for(int j=0; j<input; j++){
            if((i%2 && j%2) || !(i%2 || j%2)){
                cout << "W";
            }
            else{
                cout << "B";
            }
        }
        cout << endl;
    }

    return 0;
}