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

  int n = 0;
  lld k = 0;
  cin >> n >> k;

  vector<lld> vec(n);
  for (auto& v : vec) {
    cin >> v;
  }

  multiset<lld> record;
  auto segAdd = [&](int idx) { record.insert(vec[idx]); };
  auto segRemove = [&](int idx) { record.erase(record.lower_bound(vec[idx])); };
  auto segMax = [&](int l, int r) { return *record.rbegin(); };
  auto segMin = [&](int l, int r) { return *record.begin(); };

  lld cnt = 0;
  for (int r = 0, l = 0; r < n; r++) {
    // add vec[r]
    segAdd(r);
    while (segMax(l, r) - segMin(l, r) > k) {
      // remove vec[l]
      segRemove(l);
      l++;
    }
    cnt += r - l + 1;
  }
  cout << cnt;
  return 0;
}