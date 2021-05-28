#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1021;
typedef long long LL;
int n;
int main() {
  int t;
  scanf("%d", &t); while (t--) {
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0, x; i < n; ++i) {
      scanf("%d", &x);
      heap.push(x);
    }
    LL ans = 0;
    while (heap.size() > 1u) {
      int a1 = heap.top(); heap.pop();
      int a2 = heap.top(); heap.pop();
      a1 += a2;
      ans += a1;
      heap.push(a1);
    }
    printf("%lld\n", ans);
  }
}
