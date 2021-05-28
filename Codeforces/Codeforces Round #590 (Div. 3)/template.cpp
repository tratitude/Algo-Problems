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

    random_device rd;
    default_random_engine gen = std::default_random_engine(rd());
    uniform_int_distribution<int> dis(1, 10);
    vector<int> v;

    for(int i=0; i<10; i++){
        v.push_back(dis(gen));
    }

    sort(ALL(v));

    for(auto &i:v){
        cout << i << " ";
    }

    cout << endl;

    auto lower = lower_bound(ALL(v), 0);

    if(lower != v.end()){
        cout << *lower << endl;
    }
    else{
        cout << "not found" << endl;
    }

    return 0;
}