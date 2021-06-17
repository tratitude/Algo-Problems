// Transform to Knapsack DP Approach
// Time complexity: O(M*N)
// Space complexity: O(M*N)
// M: size of nums
// N: (target + sum of nums) / 2
class Solution {
public:
    int knapsack(vector<int>& nums, int target) {
        int N = nums.size();
        vector<vector<int>> dp(N+1, vector<int> (target+1, 0));
        for(int i = 0; i <= N; i++)
            dp[i][0] = 1;
        for(int i = 1; i <= N; i++) {
            for(int j = 0; j <= target; j++) {
                if(j >= nums[i-1]) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int n : nums)
            sum += n;
        if(sum < target || (target + sum) % 2)
            return 0;
        
        return knapsack(nums, (target + sum) / 2);
    }
};

// Recursion with Memoization Approach
// Time complexity: O(M*N)
// Space complexity: O(M*N)
// M: size of nums
// N: range of target value
class Solution {
  unordered_map<string, int> memo;

 public:
  int backtrack(vector<int>& nums, int cur, int target) {
    string key = to_string(cur) + "," + to_string(target);
    if (memo.count(key)) return memo[key];
    int res = 0;
    if (cur == nums.size()) {
      if (target == 0) {
        res = 1;
      }
      memo[key] = res;
      return res;
    }

    int subNum = backtrack(nums, cur + 1, target + nums[cur]);
    int addNum = backtrack(nums, cur + 1, target - nums[cur]);

    res = subNum + addNum;
    memo[key] = res;

    return res;
  }
  int findTargetSumWays(vector<int>& nums, int target) {
    return backtrack(nums, 0, target);
  }
};

// Brute Force Approach
// Time complexity: O(2^N)
// Space complexity: O(N)
// N: size of nums
class Solution {
    int res = 0;
public:
    void backtrack(vector<int>& nums, int cur, int target) {
        if(cur == nums.size()) {
            if(target == 0) {
                ++res;
            }
            return;
        }

        backtrack(nums, cur + 1, target + nums[cur]);
        backtrack(nums, cur + 1, target - nums[cur]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums, 0, target);
        return res;
    }
};
