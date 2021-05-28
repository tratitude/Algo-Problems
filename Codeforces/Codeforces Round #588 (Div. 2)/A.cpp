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

    vector<int> a;
    int total = 0;
    for (int i = 0; i < 4; i++)
    {
        int num;
        cin >> num;
        a.push_back(num);
        total += num;
    }

    sort(ALL(a));

    bool ans = false;
    if (total % 2)
    {
    }
    else
    {
        int half = (int)total / 2;
        if (half == a[3] && half == a[0] + a[1] + a[2])
        {
            ans = true;
        }
        else if (half == a[3] + a[0] && half == a[1] + a[2])
        {
            ans = true;
        }
    }

    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}