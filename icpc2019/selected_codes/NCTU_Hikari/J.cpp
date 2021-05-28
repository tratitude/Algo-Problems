#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
using namespace std;

int T,mins,n,m;

bitset<510> u[50],tmp;

int main(){
    cin>>T;
    while(T--){
        mins=-1;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            cin>>u[i];
        }
        int sm=1<<m;
        for(int j=0;j<sm;j++){
            tmp.reset();
            int cnt=0;
            for(int k=0,kk=1;k<m;k++,kk<<=1){
                if(kk&j){
                    tmp|=u[k];
                    cnt++;
                }
            }
            if(tmp.count()==n){
                if(mins==-1){
                    mins=cnt;
                } else{
                    mins=min(mins,cnt);
                }
            }
        }
        cout<<mins<<'\n';
    }
}
