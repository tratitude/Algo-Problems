// priority queue approach
// Time complexity: O(N*log(N))
// Space complexity: O(N)
// N: size of stations
class Solution {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    priority_queue<int> pq;
    int fuel = startFuel;
    int res = 0, prev = 0;

    if (stations.empty()) {
      if (startFuel >= target)
        return 0;
      else
        return -1;
    }

    for (const auto& station : stations) {
      while (!pq.empty() && fuel < station[0]) {
        fuel += pq.top();
        pq.pop();
        ++res;
      }
      if (fuel < station[0]) return -1;
      pq.push(station[1]);
    }

    while (!pq.empty() && fuel < target) {
      fuel += pq.top();
      pq.pop();
      ++res;
    }
    if (fuel >= target)
      return res;
    else
      return -1;
  }
};
// DP approach
// Time complexity: O(N^2)
// Space complexity: O(N)
// N: size of stations
class Solution {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int N = stations.size();
    vector<long long> dp(N + 1, 0);
    dp[0] = startFuel;

    for (int i = 0; i < N; ++i) {
      for (int t = i; t >= 0; --t) {
        if (dp[t] >= stations[i][0]) {
          dp[t + 1] = max(dp[t + 1], dp[t] + stations[i][1]);
        }
      }
    }

    for (int t = 0; t <= N; ++t) {
      if (dp[t] >= target) {
        return t;
      }
    }
    return -1;
  }
};