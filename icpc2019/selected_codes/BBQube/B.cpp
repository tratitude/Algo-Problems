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

const ll MAXn = 1e5 + 5;

ll dp[MAXn][3];
vector<ll> v[MAXn];

void dfs(ll now, ll f)
{
    vector<ll> vv;
    for(ll k:v[now])if(k != f)dfs(k, now), vv.pb(k);
    if(!SZ(vv)){
        dp[now][0] = 0;
        dp[now][1] = 1;
        dp[now][2] = 1;
        return;
    }
    {
        ll tt1 = 0, tt2 = 0;
        for(ll x:vv)tt1 += dp[x][1], tt2 += min({dp[x][0], dp[x][1], dp[x][2]});
        dp[now][1] = min(tt1, tt2 + 1);
        dp[now][2] = tt1;
    }
    {
        vector<ll> pre, suf;
        for(ll x:vv)pre.pb(min(dp[x][1], dp[x][2])), suf.pb(min(dp[x][2], dp[x][1]));
        for(int i = 1;i < SZ(pre);i ++)pre[i] += pre[i - 1];
        for(int i = SZ(suf) - 2;i >= 0;i --)suf[i] += suf[i + 1];
        dp[now][0] = pre.back();
        for(int i = 0;i < SZ(vv);i ++){
            ll tmp = min({dp[vv[i]][0], dp[vv[i]][1], dp[vv[i]][2]});
            if(i > 0)tmp += pre[i - 1];
            if(i < SZ(vv) - 1)tmp += suf[i + 1];
            dp[now][0] = min(dp[now][0], tmp);
        }
        for(int i = 0;i < SZ(vv);i ++){
            ll tmp = dp[vv[i]][1];
            if(i > 0)tmp += pre[i - 1];
            if(i < SZ(vv) - 1)tmp += suf[i + 1];
            dp[now][1] = min(dp[now][1], tmp);
        }
        {
            ll t = dp[vv[0]][1];
            for(int i = 1;i < SZ(vv);i ++){
                ll tmp = min({dp[vv[i]][0], dp[vv[i]][1], dp[vv[i]][2]}) + t;
                if(i < SZ(vv) - 1)tmp += suf[i + 1];
                dp[now][2] = min(dp[now][2], tmp);
                t = min(t + min(dp[vv[i]][1], dp[vv[i]][2]), pre[i - 1] + dp[vv[i]][1]);
            }
        }
        {
            ll t = dp[vv.back()][1];
            for(int i = SZ(vv) - 2;i >= 0;i --){
                ll tmp = min({dp[vv[i]][0], dp[vv[i]][1], dp[vv[i]][2]}) + t;
                if(i > 0)tmp += pre[i - 1];
                dp[now][2] = min(dp[now][2], tmp);
                t = min(t + min(dp[vv[i]][1], dp[vv[i]][2]), suf[i + 1] + dp[vv[i]][1]);
            }
        }
    }
}

int main()
{
    IOS();
    int n;
    cin >> n;
    for(int i = 1;i <= n - 1;i ++){
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1, -1);
    cout << min(dp[1][1], dp[1][2]) << endl;
}
