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
    vector<int> in;
    cin >> n >> k;
    while (n--)
    {
        int num;
        cin >> num;
        in.push_back(num);
    }

    vector<int> q;
    for(int &m : in){
        bool find = false;
        if(q.size() > 0){
            for(int &qm : q){
                if(m == qm){
                    find = true;
                    break;
                }
            }
        }

        if(!find){
            if(q.size() < k){
                q.push_back(m);
            }
            else{
                q.erase(q.begin());
                q.push_back(m);
            }
        }
    }
    cout << q.size() << endl;

    for(int i=q.size()-1; i>=0; i--){
        cout << q[i] << " ";
    }

    return 0;
}