#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pll;

ll T,l,k;

int main(){
    cin>>T;
    while(T--) {
//    for(ll k=1;k<=1000000000LL;k++){
        cin>>k>>l;
        if(l>=2000){
            cout<<"-1\n";
            continue;
        }
        ll c=k/1994LL+3LL;
        ll a=1995LL*c-k;
        cout<<"1999\n";
        cout<<a<<" -1000000 -1000000 -1000000";
        assert(a>c+1&&(a+c-3000000)*1999<a&&c+1<=1000000&&a<=1000000);
        for(int i=0;i<996;i++){
            cout<<" 1 -1";
        }
        cout<<" 1 -2";
        cout<<' '<<c+1<<"\n";
    }
//    while(T--) {
//        cin>>k>>l;
//        if(l>=2000){
//            cout<<"-1\n";
//            continue;
//        }
//        ll c=k/1996LL+3LL;
//        ll a=1997LL*c-k;
//        cout<<"1999\n";
//        cout<<a<<" -1000000";
//        assert(a>c&&c>0&&(a+c-1000000)*1999<a);
//        for(int i=0;i<998;i++){
//            cout<<" 1 -2";
//        }
//        cout<<' '<<c+998<<"\n";
//    }
}
/*
1 990000000 1
 */