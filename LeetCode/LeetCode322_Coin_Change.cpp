// Time complexity: O(k*N), Space complexity: O(N)
// N: amount, k: coins.size()
/*
dp[i] = min(dp[i-coins[0]], dp[i-coins[1]], ... ,dp[i-coins[j]]) + 1
// base case
dp[0] = 0
dp[coins[0]] = dp[coins[1]] = ... = dp[coins[j]] = 1
else dp[i] = -1
*/
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for (int coin : coins)
      if (coin <= amount) dp[coin] = 1;
    bt(coins, amount, dp);
    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
  int bt(vector<int>& coins, int amount, vector<int>& dp) {
    if (amount < 0) return INT_MAX;
    if (dp[amount] >= 0) return dp[amount];

    int minCoins = INT_MAX;
    for (auto coin : coins) {
      minCoins = min(minCoins, bt(coins, amount - coin, dp));
    }
    dp[amount] = minCoins == INT_MAX ? INT_MAX : minCoins + 1;
    return dp[amount];
  }
};
#include <vector>
#include <iostream>
#include <limits>
#include <map>
using namespace std;

// DP bottom-up approach
// Time complexity: O(k*N), Space complexity: O(N)
// N: amount, k: coins.size()
int coinChange(const vector<int>& coins, int amount) {
    if(amount == 0)
        return 0;
    vector<int> dic(amount+1, amount+1);
    // base case
    dic[0] = 0;
    for(int dicIdx = 1; dicIdx <= amount; ++dicIdx){
        for(const auto &coin : coins){
            int num = dicIdx - coin;
            if(num < 0)
                continue;
            dic[dicIdx] = min(dic[dicIdx], dic[num] + 1);
        }
    }
    if(dic[amount] == amount+1)
        return -1;
    return dic[amount];
}

// ***************************************************************** //
// DP top-down approach with Brute force
// Time complexity: O(k*N), Space complexity: O(N)
// N: amount, k: coins.size()
/*
int dp(const vector<int>& coins, int amount, map<int, int> &dic)
{
    auto search = dic.find(amount);
    if(search != dic.end())
        return search->second;
    if(amount == 0)
        return 0;
    if(amount < 0)
        return -1;

    int res = numeric_limits<int>::max();
    for(const auto &coin : coins){
        int subproblem = dp(coins, amount - coin, dic);

        if(subproblem == -1)
            continue;
        res = min(res, 1 + subproblem);
    }
    if(res != numeric_limits<int>::max()){
        dic[amount] = res;
        return res;
    }
    dic[amount] = -1;
    return -1;
}
int coinChange(const vector<int>& coins, int amount) {
    map<int, int> dic;
    dp(coins, amount, dic);
    return dic[amount];
}
*/

// ***************************************************************** //
// Brute force
// Time complexity: O(N^k), Space complexity: O(N)
// N: amount, k: coins.size()
/*
int coinChange(const vector<int>& coins, int amount) {
    if(amount == 0)
        return 0;
    if(amount < 0)
        return -1;

    int res = numeric_limits<int>::max();
    for(const auto &coin : coins){
        int subproblem = coinChange(coins, amount - coin);

        if(subproblem == -1)
            continue;
        res = min(res, 1 + subproblem);
    }
    if(res != numeric_limits<int>::max())
        return res;
    return -1;
}
*/
int main ()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << coinChange(coins, amount);
}