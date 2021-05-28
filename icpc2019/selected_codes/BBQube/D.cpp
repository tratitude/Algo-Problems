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

string a,b,c;
vector<string> ans;

int main()
{
    IOS();
    cin >> a >> b >> c;
    if(a!="tapioka"&&a!="bubble") ans.pb(a);
    if(b!="tapioka"&&b!="bubble") ans.pb(b);
    if(c!="tapioka"&&c!="bubble") ans.pb(c);
    if(ans.empty()) cout << "nothing\n";
    else
    {
        for(int i=0;i<SZ(ans);++i)
            cout << ans[i] << " \n"[i+1==SZ(ans)];
    }
}
