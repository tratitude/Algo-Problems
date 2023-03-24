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

  int n = 0, m = 0;
  cin >> n >> m;

  vector<int> vecN, vecM;
  for (int i = 0; i < n; i++) {
    int num = 0;
    cin >> num;
    vecN.push_back(num);
  }
  for (int i = 0; i < m; i++) {
    int num = 0;
    cin >> num;
    vecM.push_back(num);
  }

  for (int cntM = 0, cntN = 0; cntM < m; cntM++) {
    while (cntN < n && vecN[cntN] < vecM[cntM]) ++cntN;
    cout << cntN << " ";
  }
  return 0;
}