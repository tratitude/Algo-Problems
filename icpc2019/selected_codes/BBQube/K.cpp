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

priority_queue<ll,vector<ll>,greater<ll>> pq;

int main()
{
    IOS();
    ll t,n,x,ans;
    cin >> t;
    while(t--)
    {
        cin >> n,ans=0;
        while(!pq.empty()) pq.pop();
        while(n--) cin >> x,pq.push(x);
        while(SZ(pq)>1)
        {
            ll a=pq.top();
            pq.pop();
            ll b=pq.top();
            pq.pop();
            ans+=a+b;
            pq.push(a+b);
        }
        cout << ans << "\n";
    }
}
