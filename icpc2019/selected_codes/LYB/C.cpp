#include <bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string ans = "yes";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (i == j) continue;
                if (j == k) continue;
                if (i == k) continue;
                if (abs(a[i] - a[j]) % a[k] != 0) {
                    ans = "no";
                }
            }
        }
    }
    cout << ans << endl;
}

