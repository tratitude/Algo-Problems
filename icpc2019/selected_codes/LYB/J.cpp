#include <bits/stdc++.h>
using namespace std;

typedef bitset<506> bst;

bst b[17];

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int m, n; cin >> m >> n;
        b[n].reset();
        for (int i = 0; i < n; ++i) {
            b[i].reset();
            for (int j = 0; j < m; ++j) {
                char c; cin >> c;
                if (c == '1') {
                    b[i][j] = 1;
                }
                b[n][j] = 1;
            }
        }
        int ans = 7122;
        for (int i = 0; i < (1 << n); ++i) {
            bst h;
            h.reset();
            int sz = 0;
            for (int j = 0; j < n; ++j) {
                if ((((1 << j) & i) != 0)) {
                    h |= b[j];
                    ++sz;
                }
            }
            if (h == b[n]) {
                ans = min(ans, sz);
            }
        }
        if (ans == 7122) cout << -1 << endl;
        else cout << ans << endl;
    }
}

