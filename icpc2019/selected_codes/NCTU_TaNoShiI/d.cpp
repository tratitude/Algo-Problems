#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<string> v;
	string s;	
	while(cin>>s){
		if(s=="tapioka"||s=="bubble");
		else
		v.push_back(s);	
	}
//	reverse(v.begin(),v.end());
//	while(!v.empty()&&(v.back()=="tapioka"||v.back()=="bubble"))v.pop_back();
	if(v.empty())printf("nothing\n");
	else{	
		//reverse(v.begin(),v.end());
		for(auto it:v)
		cout<<it<<" ";	
		cout<<endl;	
	}
	
}
