#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		vector<bitset<500> > v;
		for(int i=0;i<m;i++){
			bitset<500> b(0);
			for(int j=0;j<n;j++){
				char c;
				scanf(" %c",&c);
				if(c=='0');
				else	
				b[j]=1;		
			}		
			v.pb(b);
		}
		int res=1e9;
		for(int i= 0;i<(1<<m);i++){
			bitset<500> ans(0);
			for(int j=0;j<m;j++){
				if(i&(1<<j)){
					ans|=v[j];
				}			
			}		
			if(ans.count()==n)
				res=min(res,__builtin_popcount(i));
		}
		if(res==1e9)res=-1;
		printf("%d\n",res);
	}
}
