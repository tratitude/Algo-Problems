// Time complexity: O(M*2^N)
// Space complexity: O(N)
// N: size of nums
// M: k
class Solution {
 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (nums.size() < k || sum % k) return false;

    vector<bool> visited(nums.size(), false);

    return solve(nums, visited, sum / k, 0, 0, k);
  }

  bool solve(vector<int>& nums, vector<bool>& visited, int target, int sum,
             int start, int k) {
    if (k == 1) return true;

    if (sum == target) return solve(nums, visited, target, 0, 0, k - 1);

    for (int j = start; j < nums.size(); j++) {
      if (visited[j] || sum + nums[j] > target) continue;

      visited[j] = true;

      if (solve(nums, visited, target, sum + nums[j], j + 1, k)) return true;

      visited[j] = false;
    }
    return false;
  }
};
// Time complexity: O(N^M)
// Space complexity: O(N+M)
// N: size of nums
// M: k
class Solution {
 public:
  bool backtrack(int cur, vector<int>& nums, vector<int>& record) {
    int N = nums.size();
    if (cur == N) {
      bool res = true;
      for (int r : record) {
        if (r != 0) {
          res = false;
          break;
        }
      }
      return res;
    }
    for (auto& r : record) {
      if (nums[cur] <= r) {
        r -= nums[cur];
        if (backtrack(cur + 1, nums, record)) return true;
        r += nums[cur];
      }
    }
    return false;
  }
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k) return false;
    int avg = sum / k;

    sort(nums.begin(), nums.end(), greater<>());
    vector<int> record(k, avg);

    return backtrack(0, nums, record);
  }
};