#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, top;
  cin >> N >> top;

  vector<int> org(N), sorted(N);

  for (int i = 0; i < N; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    org[i] = a + b + c;
    sorted[i] = org[i];
  }

  sort(sorted.begin(), sorted.end(), greater<>());

  int bar = sorted[top - 1] - 300;
  for (int num : org) {
    if (num >= bar) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}