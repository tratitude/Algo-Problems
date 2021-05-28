#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		priority_queue<long long ,vector<long long >,greater<long long >> pq;
		for(int i = 0;i<n;i++){
			int x;
			scanf("%d",&x);
			pq.push(x);		
		}	
		long long ans=0;
		while(pq.size()>1){
			long long  x=pq.top();
			pq.pop();
			long long y=pq.top();
			pq.pop();
			ans+=x+y;
			pq.push(x+y);		
		}
		printf("%lld\n",ans);
	}
}
