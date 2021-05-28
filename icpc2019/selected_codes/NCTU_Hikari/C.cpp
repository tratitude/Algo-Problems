#include <bits/stdc++.h>
using namespace std;
long long n,a[1000];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int flag=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(i!=j&&j!=k&&i!=k){
                    if((a[i]-a[j])%a[k]!=0){
                        flag=0;
                    }
                }
            }
        }
    }
    if(flag){
        cout<<"yes\n";
    }else{
        cout<<"no\n";
    }
}
