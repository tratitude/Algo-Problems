#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
// Failed try
/*
class Solution {
  int N;
  // {scoreA, scoreB}
  using pii = pair<int, int>;
  using ppii = pair<pii, pii>;
  vector<vector<ppii>> dp;
  vector<int> stone;

 public:
  // find maximum score of each in [start, end]
  pii score(bool turnA, int start, int end) {
    if (dp[start][end] != (ppii){{0, 0}, {0, 0}}) {
      if (turnA) {
        return dp[start][end].first;
      } else {
        return dp[start][end].second;
      }
    }

    // base case
    if (end == start + 1) {
      int maxNum = stone[start] > stone[end] ? stone[start] : stone[end];
      int minNum = stone[start] <= stone[end] ? stone[start] : stone[end];
      dp[start][end] = {{maxNum, minNum}, {minNum, maxNum}};
      if (turnA) {
        return {maxNum, minNum};
      } else {
        return {minNum, maxNum};
      }
    }

    auto startScore = score(!turnA, start + 1, end);
    auto endScore = score(!turnA, start, end - 1);

    // update dp
    int startScoreDiff = startScore.first - startScore.second;
    int endScoreDiff = endScore.first - endScore.second;
    pii maxScore = startScoreDiff > endScoreDiff ? startScore : endScore;
    pii minScore = startScoreDiff <= endScoreDiff ? startScore : endScore;
    dp[start][end] = {maxScore, minScore};

    if (turnA) {
      return maxScore;
    } else {
      return minScore;
    }
  }
  int stoneGameVII(vector<int>& stones) {
    N = stones.size();
    stone = stones;
    // init dp
    for (int i = 0; i < N; i++) {
      vector<ppii> vppii;
      for (int j = 0; j < N; j++) {
        vppii.push_back({{0, 0}, {0, 0}});
      }
      dp.push_back(vppii);
    }

    auto [scoreA, scoreB] = score(true, 0, N - 1);
    return scoreA - scoreB;
  }
};
*/
// Time complexity: O(N^2)
// Space complexity: O(N^2)
class Solution {
 public:
  static const int maxn = 1005;
  int dp[maxn][maxn];
  int run(int l, int r, int sum, vector<int>& v) {
    if (dp[l][r]) {
      return dp[l][r];
    }
    if (l == r) {
      return 0;
    }
    int left = sum - v[l] - run(l + 1, r, sum - v[l], v);
    int right = sum - v[r] - run(l, r - 1, sum - v[r], v);
    dp[l][r] = max(left, right);
    return dp[l][r];
  }
  int stoneGameVII(vector<int>& stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int n = (int)stones.size();
    run(0, n - 1, sum, stones);
    return dp[0][n - 1];
  }
};
int main()
{
  Solution sol;
  vector<int> stones = {5, 3, 1, 4, 2};
  cout << sol.stoneGameVII(stones);
}