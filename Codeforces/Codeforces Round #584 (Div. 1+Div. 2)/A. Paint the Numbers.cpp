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

    int n;
    vector<int> input;

    cin >> n;
    int max=0;
    while(n--){
        int in;
        cin >> in;
        input.push_back(in);
        max = in > max ? in : max;
    }
    sort(ALL(input));
/*
    bool prime[max+1];
    for(int i=0; i<=max; i++)
        prime[i]=true;

    int bound = pow(max, 0.5);
    for(int i=2; i<=bound; i++){
        if(prime[i]){
            for(int j=2; j*i<=max; j++){
                prime[j*i] = false;
            }
        }
    }
*/
/*
    for(int i=2; i<=max; i++){
        if(prime[i])
            cout << i << endl;
    }
*/
    
    int ans = 0;
    for(auto it=input.begin(); it!=input.end(); it++){
        bool isAns = false;
        int x = *it;
        if(x<0)
            continue;
        for(auto check=input.begin(); check!=input.end(); check++){
            if(!(*check % x) && *check > 0){
                if (!isAns)
                    ans++;
                *check = -1;
                isAns = true;
            }
        }
    }
/*
    for(int i=2; i<=max; i++){
        if(prime[i]){
            bool isAns = false;
            for(auto it=input.begin(); it!=input.end();){
                if(!(*it % i)){
                    if(!isAns)
                        ans++;
                    it = input.erase(it);
                    isAns = true;
                }
                else
                    it++;
            }
        }
    }
*/
    cout << ans << endl;
    return 0;
}