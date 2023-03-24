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

  int m = 0, n = 0;
  cin >> m >> n;

  vector<int> vecM, vecN;

  for (int i = 0; i < m; i++) {
    int num = 0;
    cin >> num;
    vecM.push_back(num);
  }
  for (int i = 0; i < n; i++) {
    int num = 0;
    cin >> num;
    vecN.push_back(num);
  }

  int cntM = 0, cntN = 0;
  while (cntM < m || cntN < n) {
    if (cntM < m && vecM[cntM] < vecN[cntN]) {
      cout << vecM[cntM++];
    } else {
      cout << vecN[cntN++];
    }
  }
  return 0;
}