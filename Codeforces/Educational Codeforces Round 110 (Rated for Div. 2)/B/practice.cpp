#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    while(t--) {
        int n = 0;
        cin >> n;
        vector<int> vec(n);

        for(auto& v : vec)
            cin >> v;
        
        // even numbers should before odd
        sort(vec.begin(), vec.end(), [](int x, int y){
            return x%2 < y%2;
        });

        int res = 0;
        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                if(__gcd(vec[i], vec[j]*2) > 1)
                    ++res;
            }
        }

        cout << res << "\n";
    }
}