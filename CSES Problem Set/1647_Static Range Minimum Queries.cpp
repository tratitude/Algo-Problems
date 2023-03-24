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

  int n = 0, q = 0;
  cin >> n >> q;

  vector<int> nums(n);
  for (auto& num : nums) cin >> num;

  const int Log = 20;
  vector<vector<int>> sparse_table(Log, vector<int>(n));
  sparse_table[0] = nums;
  for (int i = 1; i < Log; i++) {
    int len = (1 << (i - 1));
    for (int j = 0; j + len < n; j++) {
      sparse_table[i][j] =
          min(sparse_table[i - 1][j], sparse_table[i - 1][j + len]);
    }
  }

  auto findMin = [&](int l, int r) {
    int len = r - l + 1;
    int log = 32 - __builtin_clz(len) - 1;
    // cout << log << " " << r - (1 << log ) + 1 << endl;
    return min(sparse_table[log][l], sparse_table[log][r - (1 << log) + 1]);
  };

  while (q--) {
    int l = 0, r = 0;
    cin >> l >> r;
    cout << findMin(l - 1, r - 1) << endl;
  }

  return 0;
}