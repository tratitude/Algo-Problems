#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;
// TLE... Need to fix later
class Solution {
  // {number order, number of changes in the order}
  using psi = pair<vector<int>, int>;
  const int mod = 1e9 + 7;

 public:
  int kInversePairs(int n, int k) {
    int res = 0;
    queue<psi> q;
    unordered_set<string> memo;
    // init queue
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      v[i] = i;
    }
    q.push({v, 0});

    while (!q.empty() and q.front().second < k) {
      auto [order, change] = q.front();
      q.pop();

      for (int i = 0; i < n - 1; i++) {
        if (order[i] < order[i + 1]) {
          swap(order[i], order[i + 1]);
          string s;
          for(const auto& v : order) {
            s += to_string(v) + ',';
          }
          if (!memo.count(s)) {
            q.push({order, change + 1});
            // update memo
            memo.insert(s);
          }
          swap(order[i], order[i + 1]);
        }
      }
    }
    while (!q.empty() and q.front().second == k) {
      ++res;
      q.pop();
    }
    return res % mod;
  }
};
int main()
{
  Solution sol;
  cout << sol.kInversePairs(10, 1);
}