#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
using namespace std;

struct datas{
    int a[7][7],w;
    bool operator<(const datas &x)const{
        for(int i=0;i<6;i++) {
            for(int j=0;j<6;j++){
                if(x.a[i][j]<a[i][j]){
                    return 1;
                }
                if(x.a[i][j]>a[i][j]){
                    return 0;
                }
            }
        }
        return 0;
    }

}tmp;
set<datas> s;
queue<datas> q;
int main(){
    tmp.w=0;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cin>>tmp.a[i][j];
        }
    }
    q.push(tmp);
    int cnt=0;
    while(!q.empty()) {
        ++cnt;
        tmp=q.front(),q.pop();
        if(tmp.w>8){
            break;
        }

        int ttmp=tmp.w;
        tmp.w=0;
        if(s.find(tmp)!=s.end())
            continue;
        s.insert(tmp);
        tmp.w=ttmp;

        if(tmp.a[2][4]==tmp.a[2][5]&&tmp.a[2][4]==1){
           cout<<tmp.w+2<<'\n';
           return 0;
        }
        tmp.w++;
        for(int i=1;i<=10;i++){
            int tl=10000,tr=-10000,tu=-10000,td=10000;
            for(int j=0;j<6;j++){
                for(int k=0;k<6;k++){
                    if(tmp.a[j][k]==i){
                        tl=min(tl,j);
                        tr=max(tr,j);
                        tu=max(tu,k);
                        td=min(td,k);
                    }
                }
            }
            if(tl==10000)
                continue;
            if(tl!=tr){
                if(tl&&tmp.a[tl-1][tu]==0){
                    swap(tmp.a[tl-1][tu],tmp.a[tr][tu]);
                    q.push(tmp);
                    swap(tmp.a[tl-1][tu],tmp.a[tr][tu]);
                }
                if(tr!=5&&tmp.a[tr+1][tu]==0){
                    swap(tmp.a[tr+1][tu],tmp.a[tl][tu]);
                    q.push(tmp);
                    swap(tmp.a[tr+1][tu],tmp.a[tl][tu]);
                }
            } else{
                if(td&&tmp.a[tl][td-1]==0){
                    swap(tmp.a[tl][td-1],tmp.a[tl][tu]);
                    q.push(tmp);
                    swap(tmp.a[tl][td-1],tmp.a[tl][tu]);
                }
                if(tu!=5&&tmp.a[tr][tu+1]==0){
                    swap(tmp.a[tl][tu+1],tmp.a[tl][td]);
                    q.push(tmp);
                    swap(tmp.a[tl][tu+1],tmp.a[tl][td]);
                }
            }
        }
    }
    cout<<"-1\n";
}
/*
0 2 0 6 6 0
0 2 0 0 7 0
0 3 1 1 7 0
0 3 4 4 8 0
0 5 5 5 8 0
0 0 0 0 0 0


 */
