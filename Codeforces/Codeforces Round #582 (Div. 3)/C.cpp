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

    int counter=0;
    cin >> counter;
    while(counter--){
        lld page, divider;
        cin >> page >> divider;

        lld q = (lld)page/divider;
        int digit = divider % 10;
        int q_digit = q % 10;
        int digit_10times = digit;
        lld ans = 0;

        if(q >= 10){
            for(int i=2; i<10; i++)
                digit_10times += (digit * i)%10;
            ans += digit_10times * (lld)((q-q_digit)/10);
        }
        for (int i = 1; i <= q_digit; i++)
            ans += (digit * i) % 10;
        cout << ans << endl;
    }
    return 0;
}