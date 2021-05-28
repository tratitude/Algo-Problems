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

    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;

        int ans = 0;
        double avg = 0;
        vector<int> a;
        for(int i=0; i<n; i++){
            int in;
            cin >> in;
            a.push_back(in);
            avg += in;
        }
        ans = (int)ceil(avg/n);
        
        cout << ans << endl;

    }
    return 0;
}