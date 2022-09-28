#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, start, ans = 0;
  cin >> N >> start;
  start--;
  vector<int> nums(N);
  vector<bool> known(N, false);

  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    nums[i] = num - 1;
  }
  while (!known[start]) {
    ++ans;
    known[start] = true;
    start = nums[start];
  }

  cout << ans;
}