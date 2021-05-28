#include<bits/stdc++.h>
using namespace std;
vector<int> v;
#define pb push_back
int k;
bool solve(){
	int n;
	scanf("%d %d",&k,&n);
	if(n>=2000){
		printf("-1\n");
		return 0;
	}	
	printf("1999\n");
	for(int i = 1;;i++){
		int tmp=k+i*1999;
		for(int j =2;j<100;j++){
			if(tmp%j==0){
				int a=tmp/j;
				int x=j/2;
				int y=j-x;
				int c=i;
				int b=c+1;
				int n=1999;
				//printf("%d %d %d %d %d %d %d\n",a,b,c,n,x,y,j);
				printf("%d ",b-c);
				v.pb(b-c);
				for(int i = 1;i<x;i++)
				printf("0 "),v.pb(0);
				for(int i=1;i<y;i++)
				printf("0 "),v.pb(0);
				printf("%d ",-b),v.pb(-b);
				int now=a;
				for(int i=0;i<n-x-y;i++){
					int val=min(now,1000000);
					printf("%d",val),v.pb(val);
					if(i!=n-x-y-1)printf(" ");					
					now-=val;
				}
				printf("\n");	
				return 1;		
			}		
		}	
	}
	return 1;
}
long long solve1(){
	long long res=0;
	long long  Max=0;
	long long  l=-1;
	for(int i = 0;i<1999;i++){
		Max=Max+v[i];
		assert(abs(v[i])<=1000000);
		if(Max<0)Max=0,l=i;
		res = max(res,(i-l)*Max);
	}
	return res;
}
long long solve2(){
	long long ans=0;
	for(int i = 0;i<1999;i++){
		long long tmp=0;
		for(int j=i;j<1999;j++){
			tmp+=v[j];
			ans=max(ans,tmp*(j-i+1));
		}	
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		v.clear();		
		if(solve()){
			assert(solve1()+k==solve2());
			//printf("%lld %lld\n",solve1(),solve2());
			assert(v.size()==1999);		
		}
	}
}
