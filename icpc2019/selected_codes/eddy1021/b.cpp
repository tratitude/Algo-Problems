// eddy1021
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
int n, dp[N][3];
vector<int> v[N];
// 0 -> V V
// 1 -> V X
// 2 -> X X
void go(int now, int prt) {
  vector<int> son;
  for (auto s: v[now]) {
    if (s == prt) {
      continue;
    }
    go(s, now);
    son.push_back(s);
  }
  if (son.empty()) {
    dp[now][0] = 1;
    dp[now][1] = N;
    dp[now][2] = 0;
    return;
  }
  for (int i = 0; i< 3; ++i) {
    dp[now][i] = N;
  }
  {
    // put PMU
    dp[now][0] = 1;
    for (int s: son) {
      dp[now][0] += min(dp[s][0],
                        min(dp[s][1], dp[s][2]));
    }
  }
  {
    int ndp[2], pdp[2];
    for (int i = 0; i < 2; ++i) {
      ndp[i] = N;
    }
    ndp[0] = 0;
    for (int s: son) {
      for (int i = 0; i < 2; ++i) {
        pdp[i] = ndp[i];
        ndp[i] = N;
      }
      for (int i = 0; i < 2; ++i) {
        {
          int ni = min(i + 1, 1);
          int& to = ndp[ni];
          to = min(to, pdp[i] + dp[s][0]);
        }
        {
          int& to = ndp[i];
          to = min(to, pdp[i] + dp[s][1]);
        }
      }
    }
    dp[now][0] = min(dp[now][0], ndp[1]);
  }
  {
    int ndp[2][2], pdp[2][2];
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        ndp[i][j] = N;
      }
    }
    ndp[0][0] = 0;
    for (int s: son) {
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
          pdp[i][j] = ndp[i][j];
          ndp[i][j] = N;
        }
      }
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
          {
            int ni = min(i + 1, 1);
            int nj = j;
            int& to = ndp[ni][nj];
            to = min(to, pdp[i][j] + dp[s][0]);
          }
          {
            int& to = ndp[i][j];
            to = min(to, pdp[i][j] + dp[s][1]);
          }
          if (j == 0) {
            int ni = i;
            int nj = 1;
            int& to = ndp[ni][nj];
            to = min(to, pdp[i][j] + dp[s][2]);
          }
        }
      }
    }
    dp[now][1] = min(ndp[1][0], ndp[1][1]);
  }
  {
    int ndp[2], pdp[2];
    for (int i = 0; i < 2; ++i) {
      ndp[i] = N;
    }
    ndp[0] = 0;
    for (int s: son) {
      for (int i = 0; i < 2; ++i) {
        pdp[i] = ndp[i];
        ndp[i] = N;
      }
      for (int i = 0; i < 2; ++i) {
        {
          int& to = ndp[i];
          to = min(to, pdp[i] + dp[s][1]);
        }
        if (i == 0) {
          int& to = ndp[1];
          to = min(to, pdp[i] + dp[s][2]);
        }
      }
    }
    dp[now][2] = min(ndp[0], ndp[1]);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  go(1, 1);
  int ans = min(dp[1][0], dp[1][1]);
  printf("%d\n", ans);
}
