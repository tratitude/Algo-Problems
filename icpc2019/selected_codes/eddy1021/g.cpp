// eddy1021
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 8;
typedef unsigned long long LL;
LL all = (1LL << N) - 1;
inline int pos(int x, int y) {
  return (x << 3) | y;
}
inline void Set(LL& mask, int p, int val = 1) {
  mask &= ~((LL)1 << p);
  mask |= ((LL)val << p);
}
inline LL Val(LL mask, int p) {
  return (mask >> p) & (LL)1;
}
int n, k, l;
inline LL expand(LL nxt) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int u = 0; u < n; ++u) {
        if (Val(nxt, pos(j, u))) {
          nxt |= ((nxt >> (u * N)) & all) << (j * N);
        }
      }
    }
  }
  return nxt;
}
inline LL normalized(LL nxt) {
  bool chg;
  do {
    chg = false;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        LL nnxt = nxt;
        for (int u = 0; u < n; ++u) {
          LL vi = Val(nnxt, pos(u, i));
          LL vj = Val(nnxt, pos(u, j));
          Set(nnxt, pos(u, i), vj);
          Set(nnxt, pos(u, j), vi);
        }
        LL vi = (nnxt >> (i * N)) & all;
        LL vj = (nnxt >> (j * N)) & all;
        nnxt &= ~((LL)all << (i * N));
        nnxt &= ~((LL)all << (j * N));
        nnxt |= vi << (j * N);
        nnxt |= vj << (i * N);
        if (nnxt < nxt) {
          nxt = nnxt;
          chg = true;
        }
      }
    }
  } while (chg);
  return nxt;
}
int lpos[N], rpos[N];
void find_range(LL nxt) {
  for (int i = 0; i < n; ++i) {
    lpos[i] = 1;
    for (int j = 0; j < n; ++j) {
      if (Val(nxt, pos(j, i))) {
        ++lpos[i];
      }
    }
    rpos[i] = n - __builtin_popcountll((nxt >> (i * N)) & all);
  }
}
unordered_map<LL, int> cnt;
int dfs(LL nxt) {
  auto it = cnt.find(nxt);
  if (it != cnt.end()) {
    return it->second;
  }
  find_range(nxt);
  vector<int> cands;
  for (int i = 0; i < n; ++i) {
    if (lpos[i] <= k and k <= rpos[i]) {
      cands.push_back(i);
    }
  }
  if (cands.size() == 1u) {
    return cnt[nxt] = 0;
  }
  int ans = 100;
  vector<pair<int, int>> cand_pairs;
  for (size_t i = 0; i < cands.size(); ++i) {
    for (size_t j = i + 1; j < cands.size(); ++j) {
      int idxi = cands[i];
      int idxj = cands[j];
      if (Val(nxt, pos(idxi, idxj)) or
          Val(nxt, pos(idxj, idxi))) {
        continue;
      }
      cand_pairs.push_back({idxi, idxj});
    }
  }
  random_shuffle(cand_pairs.begin(), cand_pairs.end());
  for (auto pp: cand_pairs) {
    int idxi = pp.first;
    int idxj = pp.second;
    if (Val(nxt, pos(idxi, idxj)) or
        Val(nxt, pos(idxj, idxi))) {
      continue;
    }

    int xans = 0;
    {
      LL nnxt = nxt;
      Set(nnxt, pos(idxi, idxj));
      nnxt = expand(nnxt);
      nnxt = normalized(nnxt);
      xans = 1 + dfs(nnxt);
    }
    {
      LL nnxt = nxt;
      Set(nnxt, pos(idxj, idxi));
      nnxt = expand(nnxt);
      nnxt = normalized(nnxt);
      xans = max(xans, 1 + dfs(nnxt));
    }
    ans = min(ans, xans);
  }
  return cnt[nxt] = ans;
}
void solve(LL nxt) {
  cout << dfs(nxt) << endl;
}
int main() {
  cin >>n >> k >> l;
  LL nxt = 0;
  while (l--) {
    int x, y;
    cin >> x >> y;
    Set(nxt, pos(x, y));
  }
  nxt = expand(nxt);
  nxt = normalized(nxt);
  solve(nxt);
}
