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
    int q, c, m, x;
    cin >> q;
    while(q--){
        cin >> c >> m >> x;
        int small = c < m ? c : m;
        int big = c >= m ? c : m;
        int ans;
        if(small < (c+m+x)/3){
            ans = small;
        }
        else{
            ans = (c+m+x)/3;
        }
        cout << ans << endl;
    }
    return 0;
}