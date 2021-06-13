// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    cost.push_back(0);
    cost.push_back(0);
    vector<int> dp(cost.size(), 0);

    if (cost.size() == 4) return min(cost[0], cost[1]);

    for (int i = cost.size() - 3; i >= 0; --i) {
      dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
    }

    return min(dp[0], dp[1]);
  }
};