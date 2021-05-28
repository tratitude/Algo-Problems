#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    ll T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        cout << ((n * (n + 1)) ^ (n + 1)) << endl;
    }
}

