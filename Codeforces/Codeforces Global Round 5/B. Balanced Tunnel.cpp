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
	
    int n; cin >> n;
    int ans = 0;
    bool done[n] = {false};
    queue<int> in;
    queue<int> out;

    for(int i=0; i<n; i++){
        int num; cin >> num;
        in.push(num);
    }

    for(int i=0; i<n; i++){
        int num; cin >> num;
        out.push(num);
    }

    for(int i=0; i<n; i++){
        while(done[in.front()-1]){
            in.pop();
        }
        int in_first = in.front();
        int out_first = out.front();
        if(out_first == in_first){
            in.pop();
        }
        else{
            ans++;
        }
        done[out_first-1] = true;
        out.pop();
    }
    cout << ans << endl;

	return 0;
}

/*
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
	
    int n; cin >> n;
    int ans = 0;
    vector<int> in;
    map<int, int> out;

    for(int i=0; i<n; i++){
        int num; cin >> num;
        in.push_back(num);
    }

    for(int i=0; i<n; i++){
        int num; cin >> num;
        out.insert({num,i});
    }

    for(int i=n-1; i>=0; i--){
        int comp = out.find(in[i])->second;
        bool flag = false;
        for(int j=i-1; j>=0; j--){
            if(out.find(in[j])->second > comp){
                flag = true;
                break;
            }
        }
        if(flag){
            ans++;
        }
        
    }

    cout << ans << endl;

	return 0;
}
*/