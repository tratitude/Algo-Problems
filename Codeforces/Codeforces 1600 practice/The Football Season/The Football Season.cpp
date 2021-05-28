/*
Tags: brute force, math, number theory, *1900
Link: https://codeforces.com/problemset/problem/1244/C
*/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ALL(x) x.begin(), x.end()
 
typedef long long int lld;
typedef pair<int, int> pii;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);
	cout << fixed;
	
    lld n, p, d, w;
    cin >> n >> p >> w >> d;

    if(p > n*w){
        cout << -1;
        return 0;
    }

    for(lld i=0; i<w; i++){
        lld wx = p-d*i;
        if(wx >=0 && wx%w == 0){
            cout << wx/w << " " << i << " " << n - wx/w - i << endl;
            return 0;
        }
    }

    cout << -1;

	return 0;
}