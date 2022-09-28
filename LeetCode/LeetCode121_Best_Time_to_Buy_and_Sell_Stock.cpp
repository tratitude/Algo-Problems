// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int ans = 0;
    int minPrice = prices[0];

    for (int i = 1; i < prices.size(); i++) {
      minPrice = min(minPrice, prices[i]);
      ans = max(ans, prices[i] - minPrice);
    }

    return ans;
  }
};