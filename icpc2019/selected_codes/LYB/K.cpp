#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    int T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        ll ans = 0;
        while (n--) {
            ll x; cin >> x;
            pq.push(x);
        }
        while (pq.size() != 1) {
            ll a = pq.top(); pq.pop();
            ll b= pq.top(); pq.pop();
            ans += (a + b);
            pq.push(a + b);
        }
        cout << ans << endl;
    }
}

