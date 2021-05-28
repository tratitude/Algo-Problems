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

    int n,k,ans;
    cin >> n >> k;

    char num[n];
    cin >> num;

    if(n==1 && k == 1){
        strcpy(num, "0");
    }
    else{
        int change = k > n ? n : k;

        for(int i=0; i<change; i++){
            if (i == 0)
            {
                if(num[i] == '1' && change<n){
                    change++;
                }
                num[i] = '1';
            }
            else
            {
                if (num[i] == '0' && change < n)
                {
                    change++;
                }
                num[i] = '0';
            }
        }
    }
    for(int i=0; i<n; i++)
        cout << num[i];
/*
    char c;
    cin >> c;
*/
    return 0;
}