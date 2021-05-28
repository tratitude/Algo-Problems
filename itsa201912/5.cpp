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

    int cases=0; cin >> cases;
    while(cases--){
        int a1, a2, b1, b2;
        char c;
        cin >> a1 >> c >> a2 >> c >> b1 >> c >> b2;
        //cout << a1 << "/" << a2 << "," << b1 << "/" << b2 << endl;

        int Gcd = __gcd(a2, b2);
        int lcm = a2 * b2 / Gcd;
        
        int x = lcm/a2 * a1;
        int y = lcm/b2 * b1;
        int same = 1;
        
        // add
        same = __gcd(x+y, lcm);
        cout << (x+y)/same << "/" << lcm/same << endl;
        // sub
        same = __gcd(x-y, lcm);
        cout << (x-y)/same << "/" << lcm/same << endl;
        // mul
        same = __gcd(a1*b1, a2*b2);
        cout << a1*b1/same << "/" << a2*b2/same << endl;
        // div
        swap(b1, b2);
        same = __gcd(a1*b1, a2*b2);
        cout << a1*b1/same << "/" << a2*b2/same << endl;
    }
    return 0;
}