#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long int lld;
typedef pair<int, int> pii;

#define COIN 6

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(15);
    cout << fixed;

    int cases=0; cin >> cases;
    int coin[COIN] = {500, 100, 50, 10, 5, 1};
    while(cases--){
        int money; cin >> money;
        money = 1000 - money;
        int out[COIN];
        int total = 0;

        for(int i=0; i<COIN; i++){
            out[i] = 0;
        }
        for(int i=0; i<COIN; i++){
            out[i] = int (money/coin[i]);
            money -= out[i] * coin[i];
            if(i > 1){
                total += out[i];
            }
            
            if(!money){
                break;
            }
        }

        cout << total << endl;
        for(int i=0; i<COIN-1; i++){
            cout << out[i] << " ";
        }
        cout << out[COIN-1] << endl;
    }
    return 0;
}