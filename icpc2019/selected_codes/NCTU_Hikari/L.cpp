#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pll;

int T,n;
pll a[10000];

ll area2(pll a,pll b,pll c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

bool f(pll a,pll b,pll c){
    return area2(a,b,c)>0;
}

int main(){
    cin>>T;
    while(T--) {
        cin>>n;
        for(int i=0;i<n;i++) {
            cin>>a[i].x>>a[i].y;
        }
        sort(a,a+n);
        vector<pll> v;
        v.pb(a[0]);
        for(int i=1;i<n;i++){
            while(v.size()>1&&f(v[v.size()-2],v[v.size()-1],a[i])){
                v.pop_back();
            }
            v.pb(a[i]);
        }
        int l=v.size();
        for(int i=n-2;i>-1;i--){
            while(v.size()-l>=1&&f(v[v.size()-2],v[v.size()-1],a[i])){
                v.pop_back();
            }
            v.pb(a[i]);
        }
//        for(auto i:v){
//            cout<<i.x<<' '<<i.y<<'\n';
//        }
        reverse(v.begin(),v.end());v.pop_back();
        const int sz=v.size();
        ll ans=0;
        if(sz==3){
            pll A=v[0],B=v[1],C=v[2];
            ll area=area2(A,B,C);
            for(int i=0;i<n;i++){
                pll D=a[i];
                if(D!=A&&D!=B&&D!=C){
                    ans=max(ans,area-area2(A,B,D));
                    ans=max(ans,area-area2(B,C,D));
                    ans=max(ans,area-area2(C,A,D));
                }
//                cout<<D.x<<' '<<D.y<<'\n';
            }
        } else {
            auto next = [&](int i) { return (i + 1) % sz; };
            for (int i = 0; i < sz; i++) {
                int now = next(next(i)), l = next(i), r = next(now);
                for (int j = 0; j < sz - 3; j++, now = next(now)) {
                    while(area2(v[i],v[l],v[now])<area2(v[i],v[next(l)],v[now]))
                        l=next(l);
                    while(area2(v[i],v[now],v[r])<area2(v[i],v[now],v[next(r)]))
                        r=next(r);
//                    cout<<i<<' '<<l<<' '<<r<<'\n';
                    ans=max(ans,area2(v[i],v[now],v[r])+area2(v[i],v[l],v[now]));
                }
            }
        }
        if(ans&1)
            cout<<ans/2<<".5\n";
        else
            cout<<ans/2<<'\n';
    }
}
/*
1
4
0 0
1 0
0 1
3 2
 */