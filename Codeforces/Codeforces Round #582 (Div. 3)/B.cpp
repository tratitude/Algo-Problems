#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;

        int ans = 0;
        vector<pair<int,int>> in;
        bool check[n];
        for(int j=0; j<n; j++)
            check[j]= false;
        for(int j=0; j<n; j++){
            int num;
            cin >> num;
            in.push_back(make_pair(num, j));
        }
        sort(in.begin(), in.end());

        for(auto it = in.begin(); it != in.end(); it++){
            bool is_finished = true;
            for(int j=0; j<n; j++){
                is_finished &= check[j];
            }
            if (is_finished)
                break;
            for (int j = 0; j < it->second; j++){
                if(!check[j]){
                    check[j] = true;
                    ans++;
                }
            }
            check[it->second] = true;
        }
        cout << ans << endl;
    }
/*
    char c;
    cin >> c;
*/
    return 0;
}