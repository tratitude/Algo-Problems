#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N = 0;
    int ans = 9999999;
    vector<int> in;
    cin >> N;
    for(int i=0; i<N; i++){
        int push;
        cin >> push;
        in.push_back(push);
    }
    sort(in.begin(), in.end());
/*
    int inSize = in.size();
    auto mid = in.begin();
    for(auto it = in.begin(); it!=in.end(); it++){
        if(abs(*it - *mid)%2 )
            ans++;
    }
*/
    for (auto i = in.begin(); i != in.end(); i++){
        int hold = 0;
        for(auto it = in.begin(); it!=in.end(); it++){
        if(abs(*it - *i)%2 )
            hold++;
        }
        if (hold < ans)
            ans = hold;
    }
    cout << ans << endl;
    /*
    char c;
    cin >> c;
*/
    return 0;
}