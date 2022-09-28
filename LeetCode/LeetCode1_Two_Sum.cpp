// Hash
// Time complexity: O(N)
// Space complexity: O(N)
// N: number of nums
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) mp[nums[i]] = i;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      if (mp.count(target - nums[i]) && mp[target - nums[i]] != i) {
        ans.push_back(i);
        ans.push_back(mp[target - nums[i]]);
        break;
      }
    }

    return ans;
  }
};

// Map
// Time complexity: O(N*log(N))
// Space complexity: O(N)
// N: number of nums
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
      m.insert({nums[i], i});
      auto t = m.find(target - nums[i]);
      if (t != m.end() && t->second != i) {
        result.push_back(t->second);
        result.push_back(i);
        break;
      }
    }
    return result;
  }
};

// Brute force
// Time complexity: O(N^2)
// Space complexity: O(1)
// N: number of nums
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    for (auto i = 0; i < nums.size(); ++i) {
      for (auto j = i + 1; j < nums.size(); ++j) {
        if (nums[i] + nums[j] == target) {
          result.push_back(i);
          result.push_back(j);
        }
      }
    }
    return result;
  }
};