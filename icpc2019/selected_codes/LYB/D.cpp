#include <bits/stdc++.h>
using namespace std;

int main () {
    vector<string> v;
    int n = 3;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        if (s != "bubble" && s != "tapioka") {
            v.push_back(s);
        }
    }
    if (v.empty()) cout << "nothing" << endl;
    else {
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << " \n"[i == (int)v.size() - 1];
        }
    }
}

