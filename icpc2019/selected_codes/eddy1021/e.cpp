// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int N = 2000 - 1;
constexpr int MX = 1e6;
LL k, l, a[N];
LL sol() {
  LL ans = 0;
  for (int i = 0; i < N; ++i) {
    LL sum = 0;
    for (int j = i; j < N; ++j) {
      sum += a[j];
      ans = max(ans, sum * (j - i + 1));
    }
  }
  return ans;
}
LL wa() {
  LL result = 0, curMax = 0, left = -1;
  for (int i = 0; i < N; ++i) {
    curMax += a[i];
    if (curMax < 0) {
      curMax = 0;
      left = i;
    }
    result = max(result, (i - left) * curMax);
  }
  return result;
}
void solve() {
	if (l > N) {
		puts("-1");
		return;
	}
  LL goal = k + N;
  a[0] = -1;
  for (int i = 1; i + 1 < N; ++i) {
    a[i] = min(goal, (LL)MX);
    goal -= a[i];
  }
  a[N - 1] = goal;

  assert(sol() - wa() == k);
  
  printf("%d\n", N);
  for (int i = 0; i < N; ++i) {
    printf("%lld%c", a[i], " \n"[i + 1 == N]);
  }
}
int main() {
  int t; cin >> t; while (t --) {
    cin >> k >> l;
		solve();
  }
}
