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

    int cases = 0;
    cin >> cases;
    while (cases--)
    {
        int webin, webout;
        cin >> webin >> webout;
        float total = 0;
        if (webin < 300)
        {
            total += webin * 3;
        }
        else if (webin > 300 && webin < 500)
        {
            total += webin * 3 * 0.9;
        }
        else if (webin > 500 & webin < 1000)
        {
            total += webin * 3 * 0.75;
        }
        else if (webin > 1000)
        {
            total += webin * 3 * 0.5;
        }

        if( webout < 500)
        {
            total += webout * 6;
        }
        else if (webout > 500 & webout < 1000)
        {
            total += webout * 6 * 0.9;
        }
        else if (webout > 1000)
        {
            total += webout * 6 * 0.75;
        }
        cout << (int)total << endl;
    }

    return 0;
}