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

const ll C = 1000000;

int main()
{
    IOS();
    ll T;
    cin >> T;
    while(T--){
        int k, L;
        cin >> k >> L;
        if(L >= 2000){
            cout << -1 << endl;
            continue;
        }
        deque<ll> dq;
        if(k * 2 <= C){
            dq.pb(0);
            dq.pb(-k);
            dq.pb(2 * k);
        }else{
            ll tt = C;
            dq.pb(-C / 2);
            dq.pb(C);
            while(tt <= k + C / 2 && SZ(dq) < 1999)
            {
                dq.push_front(0);
                tt += C / 2;
            }
            while(tt <= k + C / 2){
                dq[SZ(dq) - 2] += 1;
                tt += SZ(dq);
            }
            while(tt - dq.back() != k){
                dq.back() --;
                dq[SZ(dq) - 2] ++;
            }
        }
        while(SZ(dq) < L)dq.pb(-C);
        cout << SZ(dq) << endl;
        for(int i = 0;i < SZ(dq);i ++)cout << dq[i] << " \n"[i == SZ(dq) - 1];
    }
}
