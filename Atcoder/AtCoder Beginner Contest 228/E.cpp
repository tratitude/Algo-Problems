#include <algorithm>
#include <iostream>
#include <vector>

#define LL long long
const int Mod = 998244353;
using namespace std;

int main() {
  LL N, K, M;
  cin >> N >> K >> M;

  // K^(N^M)
  // (K^N) mod A =

  LL ans = 1;
  for (LL i = 0; i < N; i++) {
    ans = ((ans % Mod) * K) % Mod;
  }

  cout << ((ans % Mod) * (M % Mod)) % Mod;
}