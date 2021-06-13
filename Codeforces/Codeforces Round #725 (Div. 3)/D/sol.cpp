// http://ideone.com/gamore
#include <bits/stdc++.h>  //works like magic, but at cost.
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define deb(x) cout << #x << " " << x << endl;
#define deb1(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; i < n; i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
template <typename... T>
void read(T&... args) {
  ((cin >> args), ...);
}
template <typename... T>
void write(T&&... args) {
  ((cout << args << " "), ...);
}
/*
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
*/
ll mpow(ll base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 1e9, M = 1e5;
//=======================

vi g[1];
int a[1];

// prime table
vi pt;

void primeTable()
{
  vector<bool> prime(N, true);
	ll i;
	for(i=2; i*i < N; i++){
		if(prime[i]){
			pt.push_back(i);
			for(ll j=i; j*i*j*i < N; j++){
				prime[j*i] = false;
			}
		}
	}
  /*
	for(; i<N; i++){
		if(prime[i])
			pt.push_back(i);
	}
  */
}

ll primeFactNum(ll num)
{
  ll fact = 0;
	for(auto m : pt){
		if(!num)
			break;
		while(!(num % m)){
			num /= m;
			++fact;
		}
	}
  if(num > 1)
    ++fact;
  return fact;
}

void solve() {
  int i, j, n, m;
  int a, b, k;
  read(a, b, k);

  int gcdNum = __gcd(a, b);
  //deb(gcdNum);

  // factorize a, b, gcdNum
  int gcdFac = primeFactNum(gcdNum);
  int facNum = primeFactNum(a/gcdNum) + primeFactNum(b/gcdNum) + gcdFac;
  //deb(facNum);
  // count factorize's power number >= k
  if( ( a != b && facNum >= k) || (a == b && k == gcdFac * 2) )
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    pt.reserve(M);
    primeTable();

    int t = 1;
    read(t);
    while(t--) {
      solve();
    }

    return 0;
}

ll mpow(ll base, int exp) {
  base %= mod;
  ll result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
    u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}