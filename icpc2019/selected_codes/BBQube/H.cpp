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

ll ans,n;

void check(ll x)
{
    ll b=(__int128)(x+n)*n/x;
    ans=max(ans,b^(x+n));
}

int main()
{
    IOS();
    ll t,x;
    cin >> t;
    while(t--)
    {
        cin >> n,ans=0,x=n*n;
        for(ll i=1;i<=n;++i)
            if(x%i==0)
                check(x),check(x/i);
        cout << ans << "\n";
    }
}
