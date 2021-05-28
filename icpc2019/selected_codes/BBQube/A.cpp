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

int tp[15], p[15], h[15], len[15]; // tp: 0 = +-i, 1 = +-j
int d[10][10];

bitset<60466176> vis;
int mn = 100, ct;

int hs(){
    ll tt = 0;
    for(int i = 0;i < ct;i ++)
        tt = tt * 6 + p[i];
    return tt;
}

void rhs(ll x){
    for(int i = ct - 1;i >= 0;i --)
        p[i] = x % 6, x /= 6;
}

void paint(int x,int c){
    if(tp[x] == 0)
        for(int i = 0;i < len[x];i ++)d[p[x] + i][h[x]] = c;
    else
        for(int i = 0;i < len[x];i ++)d[h[x]][p[x] + i] = c;
}

bool valid(int x){
    if(p[x] < 0 || p[x] + len[x] > 6)return 0;
    if(tp[x] == 0){
        if(d[p[x]][h[x]] != 0 || d[p[x] + len[x] - 1][h[x]] != 0)return 0;
    }
    else{
        if(d[h[x]][p[x]] != 0 || d[h[x]][p[x] + len[x] - 1] != 0)return 0;
    }
    return 1;
}

int main()
{
    IOS();
    for(int i = 0;i < 6;i ++)
        for(int j = 0;j < 6;j ++)cin >> d[i][j];
    
    for(int i = 0;i < 6;i ++)
        for(int j = 0;j < 6;j ++){
            if(d[i][j] != 0){
                int t = d[i][j] - 1;
                ct = max(ct, t + 1);
                if(d[i][j] == d[i][j + 2])tp[t] = 1, p[t] = j, h[t] = i, len[t] = 3, d[i][j] = d[i][j + 1] = d[i][j + 2] = 0;
                else if(d[i][j] == d[i][j + 1])tp[t] = 1, p[t] = j, h[t] = i, len[t] = 2, d[i][j] = d[i][j + 1] = 0;
                else if(d[i][j] == d[i + 2][j])tp[t] = 0, p[t] = i, h[t] = j, len[t] = 3, d[i][j] = d[i + 1][j] = d[i + 2][j] = 0;
                else if(d[i][j] == d[i + 1][j])tp[t] = 0, p[t] = i, h[t] = j, len[t] = 2, d[i][j] = d[i + 1][j] = 0;
            }
        }
    for(int i = 0;i < 6;i ++)
        for(int j = 0;j < 6;j ++)
            d[i][j] = 0;
    ll ttmp = hs();
    vis[ttmp] = 1;
    queue<pii> q;
    q.push({ttmp, 0});
    while(SZ(q)){
        if(q.front().Y > 8)break;
        int now = q.front().X, lv = q.front().Y;
        q.pop();
        rhs(now);

        for(int i = 0;i < ct;i ++)
            paint(i, 1);
        if(h[0] == 2 && p[0] == 4 && len[0] == 2){
            cout << lv + 2 << endl;
            return 0;
        }
        for(int i = 0;i < ct;i ++){
            paint(i, 0);
            p[i] --;
            if(valid(i)){
                int tmp = hs();
                if(!vis[tmp]){
                    vis[tmp] = 1;
                    q.push({tmp, lv + 1});
                }
            }
            p[i] += 2;
            if(valid(i)){
                int tmp = hs();
                if(!vis[tmp]){
                    vis[tmp] = 1;
                    q.push({tmp, lv + 1});
                }
            }
            p[i] -= 1;
            paint(i, 1);
        }
        for(int i = 0;i < ct;i ++)
            paint(i, 0);
    }
    cout << -1 << endl;
}

