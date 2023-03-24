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

  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    int num = 0;
    cin >> num;
    vec[i] = num;
  }

  lld sum = 0, cnt = 0;
  for (int r = 0, l = 0; r < n; r++) {
    sum += vec[r];
    while (sum > s) {
      sum -= vec[l];
      l++;
    }
    // 維持 [l, r] 的和不大於 s，以 r 為 segment 的起點往前找，有 r - l + 1 個 segment
    cnt += r - l + 1;
  }
  cout << cnt;
  return 0;
}