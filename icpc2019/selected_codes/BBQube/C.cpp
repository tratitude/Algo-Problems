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

int d[55];

int main()
{
    IOS();
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++)cin >> d[i];
    int fg = 1;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
            for(int k = 1;k <= n;k ++)
                if(i != j && i != k && j != k)
                    if((d[i] - d[j]) % d[k] != 0)
                        fg = 0;
    if(fg)cout << "yes" << endl;
    else cout << "no" << endl;
}
