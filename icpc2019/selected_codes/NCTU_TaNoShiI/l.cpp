#include<bits/stdc++.h>
#define LL long long 
#define pll pair<LL,LL>
#define x first
#define y second
#define mp make_pair
using namespace std;
long long cross(pll p,pll q,pll o){
	p.x-=o.x;
	p.y-=o.y;
	q.x-=o.x;
	q.y-=o.y;
	return p.x*q.y-p.y*q.x;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		map<pll,int> m;
		for(int i = 0;i<n;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			m[mp(x,y)]++;		
		}
		pll p[5005];
		n=0;
		for(auto it:m){
			p[n++]=it.x;		
		}	
		sort(p,p+n);
		pll ans[5005];
		ans[0]=p[0];
		//printf("?%d %d\n",ans[0].x,ans[0].y);
		int now=0,k=0;
		for(int tt=0;tt<2;tt++){
			for(int i =1;i<n;i++){
				while(now!=k&&cross(ans[now],p[i],ans[now-1])<=0)
					now--;
				ans[++now]=p[i];			
			}		
			k=now;
			reverse(p,p+n);		
			/*for(int i = 0;i<k;i++){
				printf("%lld %lld ",ans[i].x,ans[i].y);			
			}
			printf("\n");*/
		}

		if(k<3){
			printf("0\n");		
		}
		else if(k==3){
			pll res[5005];
			sort(p,p+n);
			res[0]=p[0];
			k=0,now=0;
			for(int tt=0;tt<2;tt++){
				for(int i =1;i<n;i++){
					while(now!=k&&cross(res[now],p[i],res[now-1])<0)
						now--;
					res[++now]=p[i];			
				}		
				k=now;
				reverse(p,p+n);		
			}
			int tot=0;
			//printf("%d\n",tot);
			for(int i=0;i<k;i++){
				tot+=m[res[i]];
			}
			if(tot>=4){
				long long res=abs(cross(ans[2],ans[1],ans[0]));
				printf("%lld",res/2);
				if(res%2)printf(".5");
				printf("\n");
			}
			else{
				//printf("?\n");
				long long res=abs(cross(ans[2],ans[1],ans[0]));
				long long sub=res;
				for(auto it:m){
					if(it.x!=ans[0]&&it.x!=ans[1]&&it.x!=ans[2]){
						sub=min(sub,abs(cross(ans[2],ans[1],it.x)));
						sub=min(sub,abs(cross(ans[0],ans[1],it.x)));
						sub=min(sub,abs(cross(ans[2],ans[0],it.x)));
					}		
				}		
				res-=sub;	
				printf("%lld",res/2);
				if(res%2)printf(".5");
				printf("\n");
			}
		}
		else{
			long long res=0;
		/*	for(int i = 0;i<k;i++){
				printf("%lld %lld\n",ans[i].x,ans[i].y);			
			}*/
			for(int i = 0;i<k;i++){
				int l=(i+1)%k,r=(i+3)%k;				
				for(int j=(i+2)%k;(j+1)%k!=i;j=(j+1)%k){
					while(abs(cross(ans[i],ans[j],ans[l]))<abs(cross(ans[i],ans[j],ans[(l+1)%k])))l=(l+1)%k;
while(abs(cross(ans[i],ans[j],ans[r]))<abs(cross(ans[i],ans[j],ans[(r+1)%k])))r=(r+1)%k;
					res=max(res,abs(cross(ans[i],ans[j],ans[l]))+abs(cross(ans[i],ans[j],ans[r])));
				}
			}
			printf("%lld",res/2);
			if(res%2)printf(".5");
			printf("\n");
		}
	}
}
