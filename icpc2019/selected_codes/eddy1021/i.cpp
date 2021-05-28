// eddy1021
# pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int N = 200;
constexpr int X = 1000;
constexpr int BS = 13131;
constexpr int mod = 1e9 + 7;
int p[X];
inline int add(int x, int y) {
  x += y;
  return x >= mod ? x - mod : x;
}
inline int mul(LL x, int y) {
  x *= y;
  return x >= mod ? x % mod : x;
}
struct {
  map<int, int> _cnt;
  void add(int x) {
    ++ _cnt[x];
  }
  bool sub(int x) {
    auto it = _cnt.find(x);
    if (it == _cnt.end()) {
      return false;
    }
    --it->second;
    if (it->second == 0) {
      _cnt.erase(it);
    }
    return true;
  }
  int max() const {
    auto it = _cnt.end();
    assert(it != _cnt.begin());
    return (--it)->first;
  }
} counter;
int n, ans[N];
bool got[X];
unordered_set<int> vst;
vector<vector<int>> o;
void add_ans() {
  vector<int> a;
  for (int i = 0; i < n; ++i) {
    a.push_back(ans[i]);
  }
  sort(a.begin(), a.end());
  o.push_back(a);
}
void output() {
  sort(o.begin(), o.end());
  o.resize(unique(o.begin(), o.end()) - o.begin());
  printf("%d\n", (int)o.size());
  for (auto a: o) {
    for (size_t i = 0; i < a.size(); ++i) {
      printf("%d%c", a[i], " \n"[i + 1 == a.size()]);
    }
  }
  exit(0);
}
void dfs(int nxt, int hsh) {
  if (nxt == n) {
    add_ans();
    return;
  }
  auto it = vst.find(hsh);
  if (it != vst.end()) {
    return;
  }
  vst.insert(hsh);
  int mx = counter.max();
  for (int cand: {mx, ans[1] - mx}) {
    if (cand < 0 or cand >= X or got[cand]) {
      continue;
    }
    vector<int> era;
    for (int i = 0; i < nxt; ++i) {
      int dst = abs(cand - ans[i]);
      if (not counter.sub(dst)) {
        break;
      }
      era.push_back(dst);
    }
    if ((int)era.size() == nxt) {
      ans[nxt] = cand;
      got[cand] = true;
      dfs(nxt + 1, add(hsh, p[cand]));
      got[cand] = false;
    }
    for (auto i: era) {
      counter.add(i);
    }
  }
}
void go() {
  ans[0] = 0;
  ans[1] = counter.max();
  got[0] = got[ans[1]] = true;
  counter.sub(ans[1]);
  dfs(2, add(p[0], p[ans[1]]));
  output();
}
int main () {
  p[0] = 1;
  for (int i = 1; i < X; ++i) {
    p[i] = mul(p[i - 1], BS);
  }
#ifdef TEST_TL
  n = N;
  set<int> s;
  s.insert(0);
  while ((int)s.size() < n) {
    s.insert(rand() % X);
  }
  //for (int i = 0; i < X; i += (X / N)) {
    //s.insert(i);
  //}
  vector<int> v;
  for (auto i : s) {
    v.push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      counter.add(abs(v[i] - v[j]));
    }
  }
#else
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1, x; j < n; ++j) {
      scanf("%d", &x);
      counter.add(x);
    }
  }
#endif
  go();
}
