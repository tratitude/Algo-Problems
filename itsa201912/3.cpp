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
        vector<int> job;
        char type;
        int jobnum; cin >> jobnum;
        for(int i=0; i<jobnum; i++){
            int j; cin >> j;
            job.push_back(j);
        }
        cin >> type;
        int total = 0;
        if(type == 'A'){
            for(int i=0; i< jobnum - 1; i++){
                total += (jobnum - i -1) * job[i];
            }
        }
        else{
            sort(ALL(job));
            for (int i = 0; i < jobnum - 1; i++)
            {
                total += (jobnum - i -1) * job[i];
            }
        }

        cout << total << endl;
    }
    return 0;
}