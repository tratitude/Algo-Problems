#include <bits/stdc++.h>
using namespace std;
long long T,n,a;
priority_queue<long long> q;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        long long ans=0;
        while(!q.empty()){
            q.pop();
        }
        for(int i=0;i<n;i++){
            cin>>a;
            q.push(-a);
        }
        while(q.size()>1){
            int ta=-q.top();
            q.pop();
            int tb=-q.top();
            q.pop();
            ans+=ta+tb;
            q.push(-ta-tb);
        }
        cout<<ans<<'\n';
    }
}
