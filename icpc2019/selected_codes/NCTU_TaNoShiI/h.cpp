#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long n;
		scanf("%lld",&n);
		long long ans=0;
		for(int i=n+1;i<n+1e7;i++){
			long long mon=n*i;
			long long son=i-n;
			if(mon%son==0){
				ans=max(ans,(mon/son)^i);			
			}	
		}
		printf("%lld\n",ans);
	}
}
