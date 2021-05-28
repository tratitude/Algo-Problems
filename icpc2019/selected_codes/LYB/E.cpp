#include <bits/stdc++.h>
using namespace std;

int main () {
    int T; cin >> T;
    while (T--) {
        int k, l; cin >> k >> l;
        if (l >= 2000) {
            cout << -1 << endl;
            continue;
        }
        int n = 1999;
        int tar = 1999 + k;
        int done = 0;
        cout << n << endl;
        for (int i = 1; i <= n; ++i) {
            if (i == 1) {
                cout << -1 << ' ';
            }
            else {
                if (done < tar % 1998) {
                    ++done;
                    cout << tar / 1998 + 1 << " \n"[i == n];
                }
                else {
                    cout << tar / 1998 << " \n"[i == n];
                }
            }
        }
    }
}

