#include <bits/stdc++.h>
 
using namespace std;
 
#define ALL(x) (x).begin(), (x).end()
 
typedef long long int lld;
typedef pair<int, int> pii;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(15);
    cout << fixed;
 
    int cases = 0;
    cin >> cases;
 
    while (cases--) {
        lld n = 0;
        int cnt[12] = { 0 };
        cin >> n;
 
        for (int i = 0; i < n; i++) {
            lld x = 0;
            cin >> x;
 
            if (x > 2048)
                continue;
            
            for (int j = 0; j < 12; j++) {
                if (x == (1 << j))
                    cnt[j]++;
            }
        }
 
        for (int j = 0; j < 11; j++) {
            if (cnt[j] >= 2) {
                cnt[j + 1] += cnt[j] / 2;
            }
        }
 
        if (cnt[11])
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
 
 
 
    return 0;
}