#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long int lld;
typedef pair<int, int> pii;

vector<int> equalElem(vector<int>& vec1, vector<int>& vec2) {
  vector<int> ret;
  for (int cnt2 = 0, cnt1 = 0; cnt2 < vec2.size(); cnt2++) {
    while (cnt1 < vec1.size() && vec1[cnt1] < vec2[cnt2]) ++cnt1;

    int eqNum = 0;
    while (cnt1 < vec1.size() && vec1[cnt1] == vec2[cnt2]) {
      ++cnt1;
      ++eqNum;
    }
    if (eqNum != 0) ret.push_back(eqNum);
  }

  return ret;
}

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

  auto equalN = equalElem(vecN, vecM);
  auto equalM = equalElem(vecM, vecN);

  lld ans = 0;
  for (int i = 0; i < equalN.size(); i++) {
    ans += (lld)equalM[i] * (lld)equalN[i];
  }

  cout << ans;
  return 0;
}