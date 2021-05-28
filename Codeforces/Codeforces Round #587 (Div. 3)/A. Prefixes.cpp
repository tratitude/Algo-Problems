#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long int lld;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(15);
    cout << fixed;

    int n, a=0, b=0, ans=0;
    vector<bool> input;
    while(n--){
        string num;
        cin >> num;
        if(num == "a"){
            input.push_back(true);
            a++;
        }
        else{
            input.push_back(false);
            b++;
        }
    }
    for(int i=0; i+1<input.size(); i+=2){
        if(input[i]==input[i+1]){
            if(a > b){
                input[i] = false;
                ans++;
            }
            else if(a < b){
                input[i] = true;
                ans++;
            }
        }
    }
    cout << ans << endl;
    for(bool num : input){
        if(num)
            cout << "a";
        else
            cout << "b";
    }
    return 0;
}