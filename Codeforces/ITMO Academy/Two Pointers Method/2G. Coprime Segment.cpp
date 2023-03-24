#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long ll;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(15);
  cout << fixed;

  int n = 0;
  cin >> n;

  vector<ll> nums(n);
  for (auto& num : nums) cin >> num;

  const int Log = 20;
  vector<vector<ll>> sparse_table(Log, vector<ll>(n));
  sparse_table[0] = nums;
  for (int i = 1; i < Log; i++) {
    int len = (1 << (i - 1));
    for (int j = 0; j + len < n; j++) {
      sparse_table[i][j] =
          gcd(sparse_table[i - 1][j], sparse_table[i - 1][j + len]);
    }
  }

  auto segGCD = [&](int l, int r) {
    int len = r - l + 1;
    int log = 32 - __builtin_clz(len) - 1;
    return gcd(sparse_table[log][l], sparse_table[log][r - (1 << log) + 1]);
  };

  int minLen = INT_MAX;
  for (int r = 0, l = 0; r < n; r++) {
    // cout << l << " " << r << " " << segGCD(l, r) << endl;
    while (l <= r && segGCD(l, r) == 1) {
      minLen = min(minLen, r - l + 1);
      l++;
    }
  }

  cout << (minLen == INT_MAX ? -1 : minLen);

  return 0;
}