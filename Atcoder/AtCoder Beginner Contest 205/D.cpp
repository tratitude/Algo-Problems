#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N = 0, Q = 0;
  cin >> N >> Q;

  vector<long long> A(N);
  for (auto& a : A) cin >> a;

  vector<long long> low(N);
  for (int i = 0; i < N; i++) {
    low[i] = A[i] - i - 1;
  }

  while (Q--) {
    long long k = 0;
    cin >> k;

    int index = lower_bound(low.begin(), low.end(), k) - low.begin();
    if (index != N) {
      cout << A[index] - 1 + k - low[index] << "\n";
    } else {
      cout << A[N-1] + k - low[N-1] << "\n";
    }
  }
  return 0;
}
