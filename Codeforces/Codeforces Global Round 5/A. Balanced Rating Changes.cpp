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
    bool posflag = false;
    bool negflag = false;
    while(n--){
        int num; cin >> num;
        if(num % 2){
            if(num < 0){
                if(negflag){
                    cout << num/2 -1 << endl;
                }
                else{
                    cout << num/2 << endl;
                }
                negflag = !negflag;
            }
            else{
                if(posflag){
                    cout << num/2 +1 << endl;
                }
                else{
                    cout << num/2 << endl;
                }
                posflag = !posflag;
            }
            
        }
        else{
            cout << num/2 << endl;
        }
    }



	return 0;
}