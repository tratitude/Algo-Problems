#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int a[55];
	for(int i = 0;i<n;i++)scanf("%d",&a[i]);
	int ok=1;
	for(int i = 0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(i!=j&&j!=k&&i!=k){
					if((a[i]-a[j])%a[k]!=0)ok=0;				
				}			
			}		
		}	
	}
	if(ok)printf("yes\n");
	else printf("no\n");
}
