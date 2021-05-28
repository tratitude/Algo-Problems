#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j; i < k; i ++)
#define MAX 5000
#define PII pair<long long, long long>
#define mp make_pair
#define F first
#define S second

PII p[MAX];
int n, idx[MAX], pos[MAX];

inline PII operator + (PII x, PII y) {
    return make_pair(x.F + y.F, x.S + y.S);
}
inline PII operator - (PII x, PII y) {
    return make_pair(x.F - y.F, x.S - y.S);
}

long long cross(PII a, PII b) {
    return a.F * b.S - a.S * b.F;
}

long long calc(PII a, PII b, PII c) {
    PII v1 = b - a, v2 = c - a;
    return abs(cross(v1, v2));
}

int cmp(PII x, PII y) {
    x = p[x.S] - p[x.F];
    y = p[y.S] - p[y.F];
    return cross(x, y) > 0;
}
int main() {
    cin.tie(0), cout.sync_with_stdio(0);
    int T; cin >> T;
    while (T--) {

        cin >> n;
        REP(i , 1 , n + 1) cin >> p[i].F >> p[i].S;
        sort(p + 1, p + 1 + n);

        REP(i , 1 , n + 1) idx[i] = i, pos[i] = i;
        
        vector<PII> v;

        REP(i , 1 , n + 1) {
            REP(j , i + 1 , n + 1) {
                v.emplace_back(i, j);
            }
        }
        sort(v.begin(), v.end(), cmp);

        long long ans = 0;    
        for (auto line : v){
            int fr = pos[line.F], ba = pos[line.S];
            if (fr > ba) swap(fr, ba);

            if (fr != 1 && ba != n) {
                long long area1 = 0;
                area1 += calc(p[idx[1]], p[idx[fr]], p[idx[ba]]);
                area1 += calc(p[idx[fr]], p[idx[ba]], p[idx[n]]);
                ans = max(ans, area1);
            }

            swap(idx[fr], idx[ba]);
            swap(pos[line.F], pos[line.S]);
        }

        if (ans % 2 == 1)
            cout << ans / 2 << ".5\n";
        else cout << ans / 2 << "\n";
    }
    return 0;
}
