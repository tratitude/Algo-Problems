#include <bits/stdc++.h>
using namespace std;
string s[3];
int main(){
    int flag=0,cnt=0;
    for(int i=0;i<3;i++){
        cin>>s[i];
        if(s[i]=="bubble"){
            flag++;
        } else if(s[i]=="tapioka"){
            flag++;
        }
        else{
            if(cnt)
                cout<<' ';
             cnt++;
             cout<<s[i];
        }
    }
    if(flag==3){
        cout<<"nothing";
    }
    cout<<'\n';
}
