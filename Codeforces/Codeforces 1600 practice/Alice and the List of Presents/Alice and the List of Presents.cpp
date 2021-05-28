/*
Tags: combinatorics, hashing, math, matrices
Link: https://codeforces.com/contest/1236/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ALL(x) x.begin(), x.end()
 
typedef long long int lld;
typedef pair<int, int> pii;

const int M = 1e9+7;

lld fact(int n){//n的阶乘求余p 
    lld ret = 1;
    for (int i = 1; i <= n ; i ++) ret = ret * i % M ;
    return ret ;
}
void ex_gcd(lld a, lld b, lld &x, lld &y, lld &d){
    if (!b) {d = a, x = 1, y = 0;}
    else{
        ex_gcd(b, a % b, y, x, d);
        y -= x * (a / b);
    }
}
lld inv(lld t){//如果不存在，返回-1 
    lld d, x, y;
    ex_gcd(t, M, x, y, d);
    return d == 1 ? (x % M + M) % M : -1;
}
lld comb(int n, int m){//C(n, m) % p
    if (m < 0 || m > n) return 0;
    return fact(n) * inv(fact(m)) % M * inv(fact(n-m)) % M;
}
lld Lucas(lld n, lld m){
        return m ? Lucas(n/M, m/M) * comb(n%M, m%M) % M : 1;
}

lld mul(lld a, lld b){//快速乘，计算a*b%p 
    lld ret = 0;
    while(b){
        if(b & 1) ret = (ret + a) % M;
        a = (a + a) % M;
        b >>= 1;
    }
    return ret;
}

lld mypow(lld a, lld b)
{
    lld ret = a;
    if(b==1)
        return ret;
    for(int i=2; i<=b; i++){
        ret = mul(ret, a) % M;
    }
    return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);
	cout << fixed;
	
    int n,m; cin >> n >> m;
    lld eachbox = mypow(2, m);
    lld ans = mypow(eachbox, n);

    for(int i=1; i<n; i++){
        lld lucas = Lucas(n, i);
        ans -= lucas * (mypow(eachbox, i) - 1);
    }
    cout << (ans-1)%M << endl;

	return 0;
}