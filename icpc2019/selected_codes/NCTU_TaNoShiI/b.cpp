#include<bits/stdc++.h>
using namespace std;
long long dp[100005][3];
vector<int> v[100005];
void dfs(int x,int f){
	if(v[x].size()==1&&f!=0){
		dp[x][0]=0;
		dp[x][1]=1;
		dp[x][2]=1;	
		return ;
	}
	for(auto it:v[x]){
		if(it!=f){
			dfs(it,x);		
		}		
	}
	long long sum=0;
	for(auto it:v[x]){
		sum+=dp[it][1];	
	}
	dp[x][0]=sum;
	long long tmp=0,tmp1=1e9;
	tmp=0,tmp1=1e9;
	for(auto it:v[x]){
		if(it!=f){
		tmp1=min(tmp1+dp[it][1],dp[it][0]+tmp);
		tmp=tmp+dp[it][1];
		}
	}
	dp[x][0]=min(tmp1,dp[x][0]);
	
	tmp=0,tmp1=1e9;
	long long tmp2=1e9,tmp3=1e9;
	for(auto it:v[x]){
		if(it!=f){
			tmp3=min(tmp3+min(dp[it][1],dp[it][2]),min(tmp2+dp[it][2],tmp1+dp[it][0]));
			tmp2=min(tmp+dp[it][0],tmp2+dp[it][1]);
			tmp1=min(tmp+dp[it][2],tmp1+min(dp[it][1],dp[it][2]));
			tmp=tmp+dp[it][1];
			//printf("%d %d %d %d %d\n",it,tmp,tmp1,tmp2,tmp3);
		}
	}
	dp[x][1]=tmp3;


	tmp=0,tmp1=1e9;
	for(auto it:v[x]){
		if(it!=f){
		tmp1=min(tmp1+min(dp[it][1],dp[it][2]),tmp+dp[it][2]);
		tmp=tmp+dp[it][1];
		}	
	}
	dp[x][2]=tmp1;
	sum=0;
	for(auto it:v[x]){
		if(it!=f){
			sum=sum+min(min(dp[it][0],dp[it][1]),dp[it][2]);		
		}	
	}
	dp[x][2]=min(sum+1,dp[x][2]);
	dp[x][1]=min(dp[x][1],dp[x][2]);
/*
	tmp=0,tmp1=1e9;
	sum=0;
	for(auto it:v[x])
	sum+=dp[it][2];
	dp[x][2]=sum;
	sum=0;
	for(auto it:v[x]){
		if(it!=f)
		sum=sum+min(min(dp[it][0],dp[it][1]),dp[it][2]);
	}
	dp[x][2]=min(dp[x][2],sum+1);*/
	//printf("%d %d %d %d\n",x,dp[x][0],dp[x][1],dp[x][2]);
}
#define pb push_back
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);	
	}
	dfs(1,0);
	printf("%lld\n",min(dp[1][1],dp[1][2]));
}
