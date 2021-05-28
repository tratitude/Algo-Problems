// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int N = 6;
constexpr int nMaxItem = 10 + 1;
constexpr int nMaxStep = 10 - 2;
#define X first
#define Y second
int arr[N][N], items, ans = -3;
pair<int, int> imn[nMaxItem], imx[nMaxItem];
inline bool in_mask(int mask, int bt) {
  return (mask >> bt) & 1;
}
void init() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> arr[i][j];
      if (arr[i][j]) {
        int idx = arr[i][j];
        if (not in_mask(items, idx)) {
          imn[idx] = {i, j};
        }
        items |= (1 << idx);
        imx[idx] = {i, j};
      }
    }
  }
}
inline int atleast() {
  int lst = -1, ret = 0;
  for (int i = 0; i < N; ++i) {
    if (arr[2][i] == 1) {
      lst = i;
      continue;
    }
    if (arr[2][i] and lst != -1) {
      ++ ret;
    }
  }
  ret += (N - 1) - lst;
  return ret;
}
bool move_dir(int idx, int dir) {
  int lx = imn[idx].X, ly = imn[idx].Y;
  int rx = imx[idx].X, ry = imx[idx].Y;
  if (lx == rx) {
    if (dir == 1) {
      if (ry + 1 == N or
          arr[rx][ry + 1]) {
        return false;
      }
      arr[rx][ry + 1] = arr[rx][ry];
      arr[lx][ly] = 0;
      ++ly; ++ry;
    } else {
      if (ly - 1 < 0 or
          arr[lx][ly - 1]) {
        return false;
      }
      arr[lx][ly - 1] = arr[lx][ly];
      arr[rx][ry] = 0;
      --ly; --ry;
    }
  } else {
    if (dir == 1) {
      if (rx + 1 == N or
          arr[rx + 1][ry]) {
        return false;
      }
      arr[rx + 1][ry] = arr[rx][ry];
      arr[lx][ly] = 0;
      ++lx; ++rx;
    } else {
      if (lx - 1 < 0 or
          arr[lx - 1][ly]) {
        return false;
      }
      arr[lx - 1][ly] = arr[lx][ly];
      arr[rx][ry] = 0;
      --lx; --rx;
    }
  }
  imn[idx] = {lx, ly};
  imx[idx] = {rx, ry};
  return true;
}
bool win() {
  return imx[1].Y == (N - 1);
}
int bnd;
vector<int> cands;
bool dfs(int step, int pre_idx, int pre_dir) {
  if (win()) {
    return true;
  }
  if (step + atleast() > bnd) {
    return false;
  }
  for (int idx: cands) {
    for (int dir: {-1, 1}) {
      if ((idx == pre_idx) and
          (dir + pre_dir) == 0) {
        continue;
      }
      if (move_dir(idx, dir)) {
        if (dfs(step + 1, idx, dir)) {
          return true;
        }
        move_dir(idx, -dir);
      }
    }
  }
  return false;
}
void solve() {
  if (not in_mask(items, 1) or
      imn[1].X != 2 or
      imx[1].X != 2) {
    return;
  }
  for (int i = 1; i < nMaxItem; ++i) {
    if (in_mask(items, i)) {
      cands.push_back(i);
    }
  }
  for (bnd = 0; bnd <= nMaxStep; ++bnd) {
    if (dfs(0, 0, 0)) {
      ans = bnd;
      return;
    }
  }
}
int main() {
  init();
  solve();
  cout << (ans + 2) << "\n";
}
