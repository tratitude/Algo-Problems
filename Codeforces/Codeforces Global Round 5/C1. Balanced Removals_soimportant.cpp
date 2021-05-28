#include <bits/stdc++.h>
 
using namespace std;
 
#define ALL(x) x.begin(), x.end()
 
typedef long long int lld;
typedef pair<int, int> pii;
 
struct point {
    int idx;
    lld x, y, z;
};
 
const int maxn = 2e3 + 5;
point pt[maxn];
bool used[maxn];
 
lld dis(point &a, point &b) {
    lld ret = 0;
    ret += (a.x - b.x) * (a.x - b.x);
    ret += (a.y - b.y) * (a.y - b.y);
    ret += (a.z - b.z) * (a.z - b.z);
 
    return ret;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(15);
    cout << fixed;
    
    int n = 0;
    cin >> n;

    priority_queue<pair<lld, pii>, vector<pair<lld, pii>>, greater<pair<lld, pii>>> pq;
 
    for (int i = 1; i <= n; i++) {
        pt[i].idx = i;
        cin >> pt[i].x >> pt[i].y >> pt[i].z;
    }
 
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            pq.emplace(make_pair(dis(pt[i], pt[j]), make_pair(i, j)));
        }
    }
 
    vector<pii> ans;
 
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
 
        if (used[top.second.first] || used[top.second.second])
            continue;
 
        ans.push_back(top.second);
        used[top.second.first] = true;
        used[top.second.second] = true;
    }
 
    for (auto &p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
 
    
 
    return 0;
}