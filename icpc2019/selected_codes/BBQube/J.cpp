#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define X first
#define Y second
#define ET cout << "\n"
#define ALL(v) v.begin(),v.end()
#define SZ(a) ((int)a.size())
#define pb push_back
#define IOS() ios::sync_with_stdio(0),cin.tie(0);

bitset<500> d[20];

int main()
{
    IOS();
    ll T;
    cin >> T;
    while(T--){
        ll n, m;
        cin >> n >> m;
        for(int i = 0;i < m;i ++)
            d[i].reset();
        for(int i = 0;i < m;i ++){
            string s;
            cin >> s;
            for(int j = 0;j < n;j ++)
                if(s[j] == '1')d[i][j] = 1;
        }
        ll mn = 100;
        for(int I = 0;I < (1<<m);I ++){
            bitset<500> tmp;
            tmp.reset();
            ll ct = 0;
            for(int i = 0;i < m;i ++)
                if(I & (1<<i))tmp |= d[i], ct ++;
            if(tmp.count() == n)mn = min(mn, ct);
        }
        if(mn == 100)cout << -1 << "\n";
        else cout << mn << endl;
    }
}
