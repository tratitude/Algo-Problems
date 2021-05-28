#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long int lld;
typedef pair<int, int> pii;

struct team_t{
    int player;
    int card;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(15);
    cout << fixed;

    int n, min=0, max=0;
    team_t t1, t2;
    cin >> t1.player >> t2.player >> t1.card >> t2.card >> n;

    if(t1.player*(t1.card-1)+t2.player*(t2.card-1) < n){
        min = n - (t1.player * (t1.card - 1) + t2.player * (t2.card - 1));
    }
    team_t big, small;
    big = t1.card > t2.card ? t1 : t2;
    small = t1.card < t2.card ? t1 : t2;

    max = n / small.card;
    if(small.player*small.card < n){
        max = small.player;
        max += (n - small.player * small.card) / big.card;
    }

    cout << min << " " << max << endl;
    return 0;
}