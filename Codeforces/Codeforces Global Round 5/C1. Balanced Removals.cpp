#include <bits/stdc++.h>
 
using namespace std;
 
#define ALL(x) x.begin(), x.end()
 
typedef long long int lld;
typedef pair<int, int> pii;

struct point{
    int x,y,z;
};
struct dis{
    int p1, p2;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);
	cout << fixed;
	
    int n; cin >> n;
    point p[n];
    map<int, dis> d;
    bool check[n] = {false};

    for(int i=0; i<n; i++){
        cin >> p[i].x >> p[i].y >> p[i].z;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int dis = pow(p[i].x-p[j].x, 2) + pow(p[i].y-p[j].y, 2) + pow(p[i].z-p[j].z, 2);
            d.insert({dis, {i, j}});
        }
    }
    
    for(auto &m : d){
        if(check[m.second.p1] || check[m.second.p2]){
            continue;
        }
        else{
            cout << m.second.p1+1 << " " << m.second.p2+1 << endl;
            check[m.second.p1] = check[m.second.p2] = true;
        }
    }

	return 0;
}