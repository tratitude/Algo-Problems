#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long int lld;
typedef pair<int, int> pii;

void encode(int x, string &str)
{
    do{
        if(x%2)
            str += "R";
        else
            str +="L";
        x /= 2;
    }while (x != 1);
    reverse(ALL(str));
}

int isElement(int n, int x)
{
    if(n < x) return -1;
    else if(n == x) return 0;
    else if(x == 0) return (int)log2(n)+1;
    else if(x == 1) return (int)log2(n);
    string strN, strX;

    encode(n, strN);
    encode(x, strX);

    int max=0;
    for(; max<strX.size(); max++){
        if(strX[max] != strN[max])
            break;
    }

    return max == strX.size() ? strN.size()-max : -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(15);
    cout << fixed;
/*
    int n, k;
    cin >> n >> k;
    vector<int> vec;
    vector<pair<int, int>> fre_times;

    for(int i=0; i<n; i++){
        auto num;
        cin >> num;
        vec.push_back(num);
    }
    sort(ALL(vec));
*/
    int n, x;
    while(cin >> n >> x){
        cout << isElement(n, x) << endl;
    }

    return 0;
}
