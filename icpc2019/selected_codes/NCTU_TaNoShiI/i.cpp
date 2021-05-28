#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

int n;

int d[2000];

vector<int> a;
int mk[2000];

vector< vector<int> > ans;

int cnt2[1001],cnt[1001];
int dVal[1001],cvt[1001];


set<ll> mkk;

ll Hash(int l,int r){
	ll ans = 0;
	ll M = 123147;
	ll mod7 = (ll)(1e9+7);
	for(int i=0;i<l;i++) ans = (ans * M + a[i] + 1)%mod7;
	for(int i=n-1;i>r;i--) ans = (ans*M+a[i]+1)%mod7;
	return ans;
}

int dfs(int l,int r,int ptr){

	ll h = Hash(l,r)  ;
	if(mkk.find(h) != mkk.end()) return 0;
	mkk.insert(h);

	/*cout<<"dfs "<<l<<' '<<r<<' '<<ptr<<endl;
	for(int i=0;i<=ptr;i++) cout<<cnt[i]<<' ';
	cout<<endl;
	for(int i=0;i<=ptr;i++) cout<<dVal[i]<<' ';
	cout<<endl;*/

	if(l > r){
		ans.pb(a);
		return 1;
	}	
	if(ptr < 0) return 0;
	
	int mx = dVal[ptr];

	int num = a[0] + mx ;

//	cout<<"m "<<mx<<' '<<num<<endl;
	
	vector<int> vv;

	int key = 0;

	for(int i=0;i<l;i++){
		if(num < a[i] || cvt[num - a[i]] == -1 || cnt[cvt[num-a[i]] ]<= 0){
			key = 1;
			break;
		}
		cnt[ cvt[ num - a[i] ] ] --;
		vv.pb(cvt[num - a[i]]);
	}
	if(key == 0){
		for(int i=n-1;i>r;i--){
			if(num > a[i] || cvt[a[i] - num] == -1 || cnt[cvt[a[i]-num]] <= 0) {
				key = 1;
				break;
			}
			cnt[ cvt[ a[i] - num ] ] --;
			vv.pb(cvt[a[i] - num]);
		}
	}
	
	if(key == 0){
		int fptr = ptr;

		while( fptr>=0 && cnt[fptr] == 0) fptr--;
		a[r] = num;
		if(dfs(l,r-1,fptr)) mkk.erase(h);
		//dfs(l,r-1,fptr);
	}
	
	for(auto f:vv){
		cnt[f]++;
	}

	vv.clear();

	num = a[n-1] - mx;
//	cout<<"m2 "<<mx<<' '<<num<<endl;
	
	key = 0;
		
	for(int i=0;i<l;i++){
		if(num < a[i] || cvt[num - a[i]] == -1 || cnt[cvt[num-a[i]]] <= 0){
			key = 1;
			break;
		}
		cnt[ cvt[ num - a[i] ] ] --;
		vv.pb(cvt[num - a[i]]);
	}
	if(key == 0){
		for(int i=n-1;i>r;i--){
			if(num > a[i] || cvt[a[i] - num] == -1 || cnt[cvt[a[i]-num]] <=0) {
				key = 1;
				break;
			}
			cnt[ cvt[ a[i] - num ] ] --;
			vv.pb(cvt[a[i] - num]);
		}
	}
	
	if(key == 0){
		int fptr = ptr;

		while( fptr>=0 && cnt[fptr] == 0) fptr--;
		a[l] = num;
		if(dfs(l+1,r,fptr)) mkk.erase(h);
//		dfs(l+1,r,fptr);
	}
	
	for(auto f:vv){
		cnt[f]++;
	}
	
	return 0;

}

int main(){
	
	scanf("%d",&n);
	a.resize(n);
	int key = 0;
	for(int i=0;i< n * (n-1) / 2;i++){
		scanf("%d",&d[i]);
		if(d[i] >= 1000) key = 1;
		else cnt2[d[i]]++;
	}
	
	memset(cvt,-1,sizeof(cvt));
	int ptt = 0;
	for(int i=0;i<=999;i++){
		if( cnt2[i] != 0 ){
			dVal[ptt] = i;
			cvt[i] = ptt;
			cnt[ptt] = cnt2[i];
			//cout<<"hi "<<ptt<<' '<<dVal[ptt]<<' '<<cvt[i]<<' '<<cnt[ptt]<<endl;
			ptt++;

		}
	}
	
	if(key == 1){
		cout<<0<<endl;
		return 0;
	}
	else{
		a[0] = 0;
		a[n-1] = d[n*(n-1)/2-1];
		cnt[ cvt[d[n*(n-1)/2-1]] ]--;
		while( cnt[ptt] == 0 ) ptt--;
		dfs( 1,n-2,ptt );
		
		if( (int)(ans.size()) == 0){
			printf("0\n");
		}	
		else{

			printf("%d\n",(int)ans.size());
			sort(ans.begin(),ans.end());
			for( auto arr:ans) {
				for(auto f:arr) printf("%d ",f);
				printf("\n");
			}
/*
			vector<int> vv1,vv2;
			for(int i=n-1;i>=0;i--){
				//cout<<"yo "<<ans[0][n-1]<<' '<<ans[0][i]<<endl;
				vv1.pb( ans[0][n-1] - ans[0][i] );
				vv2.pb( ans[0][n-1-i] );
			}	
			set< vector<int> > ansSet;
			ansSet.insert(vv2);
			ansSet.insert(vv1);
			printf("%d\n",(int)ansSet.size());
			for (auto arr : ansSet ){
				for(int i=0;i<n;i++) printf("%d ",arr[i]);
				printf("\n");
			}*/
		}

		
	}

	return 0;
}
