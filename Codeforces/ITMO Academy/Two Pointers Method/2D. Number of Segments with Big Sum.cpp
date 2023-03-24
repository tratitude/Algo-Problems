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
  lld s = 0;
  cin >> n >> s;

  vector<int> vec;
  for (int i = 0; i < n; i++) {
    int num = 0;
    cin >> num;
    vec.push_back(num);
  }

  lld cnt = 0, sum = 0;
  for (int r = 0, l = 0; r < n; r++) {
    sum += vec[r];
    while (sum >= s && l < n) {
      cnt += n - r;
      sum -= vec[l];
      l++;
    }
  }
  cout << cnt;
  return 0;
}