#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long int lld;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(15);
  cout << fixed;

  int n = 0, k = 0;
  cin >> n >> k;

  vector<int> vec(n);
  for (int& v : vec) {
    int num = 0;
    cin >> num;
    v = num;
  }

  vector<int> record(1e5 + 1, 0);
  int cnt = 0, r = 0, l = 0;
  lld ans = 0;
  for (int r = 0, l = 0; r < n; r++) {
    int numR = vec[r];
    record[numR]++;
    cnt = record[numR] == 1 ? cnt + 1 : cnt;
    while (cnt > k) {
      int numL = vec[l];
      record[numL]--;
      cnt = record[numL] == 0 ? cnt - 1 : cnt;
      l++;
    }
    ans += r - l + 1;
  }

  cout << ans;

  return 0;
}