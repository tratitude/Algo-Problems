
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    bitset<10001> bits(1);
    int sum = accumulate(nums.begin(), nums.end(), 0);
    for (auto n : nums) bits |= bits << n;
    return !(sum % 2) && bits[sum / 2];
  }
};

// Knapsack Approach with 1D DP
// Time complexity: O(N*M)
// Space complexity: O(M)
// N: size of nums
// M: summation of nums / 2
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) {
      return false;
    }
    int M = sum / 2;
    int N = nums.size();
    vector<bool> dp(M + 1, false);
    dp[0] = true;
    for (int i = 1; i <= N; i++) {
      for (int j = M; j >= 0; j--) {
        if (j >= nums[i - 1]) {
          dp[j] = dp[j - nums[i - 1]] or dp[j];
        } else {
          dp[j] = dp[j];
        }
      }
    }
    return dp[M];
  }
};

// Knapsack Approach
// Time complexity: O(N*M)
// Space complexity: O(N*M)
// N: size of nums
// M: summation of nums / 2
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) {
      return false;
    }
    int M = sum / 2;
    int N = nums.size();
    vector<vector<bool>> dp(N + 1, vector<bool>(M + 1, false));
    for (int i = 0; i <= N; i++) {
      dp[i][0] = true;
    }

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        if (j >= nums[i - 1]) {
          dp[i][j] = dp[i - 1][j - nums[i - 1]] or dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[N][M];
  }
};