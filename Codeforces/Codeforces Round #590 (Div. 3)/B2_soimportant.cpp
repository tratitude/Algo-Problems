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

    int n, k;
    cin >> n >> k;

    map<int, int> mp;
    set<pii> st;

    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;

        if (mp.count(x))
        {
            continue;
        }
        else
        {
            st.insert(pii(i, x));
            mp[x] = i;

            if (st.size() > k)
            {
                auto it = *st.begin();
                st.erase(st.begin());
                mp.erase(it.second);
            }
        }
    }

    vector<pii> ans(ALL(st));
    reverse(ALL(ans));

    cout << ans.size() << '\n';
    for (auto &p : ans)
    {
        cout << p.second << ' ';
    }
    cout << '\n';

    return 0;
}