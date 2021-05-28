#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long int lld;
typedef pair<int, int> pii;
#define Q 2048

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(15);
    cout << fixed;

    int q, n;
    cin >> q;

    while(q--){
        vector<int> input;
        cin >> n;
        bool ans = false;
        for(int i=0; i<n; i++){
            lld num;
            cin >> num;
            if(num == Q)
                ans = true;
            else if(num > Q)
                continue;
            input.push_back((int)num);
        }
        sort(ALL(input));
        while((input.size() >= 2) && !ans){
            int first = input[0];
            int second = input[1];
            input.erase(input.begin());
            if(first == second){
                if(first*2 == Q){
                    ans = true;
                }
                else{
                    input[0] *= 2;
                    sort(ALL(input));
                }
            }
        }
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}