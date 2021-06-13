#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// Time complexity: O(N*(log(N) + log(K)))
// Space complexity: O(K)
// N: n
// K: k
class Solution {
  using pii = pair<int, int>;
  const int mod = 1e9 + 7;
  struct Team {
    Team(int _k) : k(_k) {}
    // assume p.second <= teamEf
    void perf(pii p) {
      int ef = p.first;
      int sp = p.second;

      if (minSp.size() == k && minSp.top() >= sp) return;

      updateMinSp(sp);
      teamEf = ef;
      maxPerf = max(maxPerf, teamEf * teamSp);
    }
    void updateMinSp(int sp) {
      if (minSp.size() == k) {
        teamSp -= minSp.top();
        minSp.pop();
      }
      teamSp += sp;
      minSp.push(sp);
    }
    int k = 0;
    priority_queue<int, vector<int>, greater<int>> minSp;
    long long teamEf = 0;
    long long teamSp = 0;
    long long maxPerf = 0;
  };

 public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
                     int k) {
    // {ef, speed}
    vector<pii> engineer(n);
    Team team(k);
    // init engineer
    for (int i = 0; i < n; ++i) {
      engineer[i] = make_pair(efficiency[i], speed[i]);
    }

    sort(engineer.begin(), engineer.end(), greater<>());

    for (auto p : engineer) {
      team.perf(p);
    }

    return team.maxPerf % mod;
  }
};

int main() {
  Solution sol;
  int n = 6, k = 2;
  vector<int> speed = {2, 10, 3, 1, 5, 8};
  vector<int> efficiency = {5, 4, 3, 9, 7, 2};
  cout << sol.maxPerformance(n, speed, efficiency, k);
}