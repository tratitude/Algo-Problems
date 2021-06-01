// Time complexity: O(Nlog(N))
// Space complexity: O(1)
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res(2, 0);
    for (int i = 0; i < numbers.size() - 1; ++i) {
      auto it = lower_bound(numbers.begin() + i + 1, numbers.end(),
                            target - numbers[i]);
      if (it != numbers.end() && *it + numbers[i] == target) {
        res[0] = i + 1;
        res[1] = distance(numbers.begin(), it) + 1;
      }
    }
    return res;
  }
};