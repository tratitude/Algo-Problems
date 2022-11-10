// Backtracking with prefix sum approach
// Time complexity: O(N)
// Space complexity: O(M)
// N: number of nodes
// M: max depth of tree
class Solution {
    using LL = long long;
    unordered_map<LL, int> mp;
    int ans = 0, target = 0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        mp[0] = 1;
        
        find(root, 0);
        return ans;
    }
    void find(TreeNode* root, LL sum) {
        if (root == nullptr) return;

        sum += root->val;
        if (mp[sum - target] > 0)
            ans += mp[sum - target];
        mp[sum]++;
        find(root->left, sum);
        find(root->right, sum);
        mp[sum]--;
    }
};
// Time complexity: O(N^2)
// Space complexity: O(N+M)
// N: number of nodes
// M: depth of the tree
class Solution {
    int ans = 0, target = 0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;

        target = targetSum;
        subPath(root);
        return ans;
    }
    vector<long long> subPath(TreeNode* root) {
        if (root == nullptr) return {};

        auto left = subPath(root->left);
        auto right = subPath(root->right);

        vector<long long> vec = {root->val};
        foundTarget(root->val);
        for (auto num : left) {
            long long next = num + root->val;
            foundTarget(next);
            vec.push_back(next);
        }
        for (auto num : right) {
            long long next = num + root->val;
            foundTarget(next);
            vec.push_back(next);
        }
        return vec;
    }
    void foundTarget(long long num) {
        if (num == target) ++ans;
    }
};
// Time complexity: O(N^2)
// Space complexity: O(N+M)
// N: number of nodes
// M: depth of the tree
class Solution {
  using PVI = pair<vector<int>, int>;
  const int kNull = INT_MAX;
  int target = 0;
  int ans = 0;

 public:
  PVI find(TreeNode* root) {
    if (root == nullptr) {
      return {{}, kNull};
    }

    auto [left_vec, left_num] = find(root->left);
    auto [right_vec, right_num] = find(root->right);
    vector<int> vec;
    int val = root->val;

    if (val == target) ans++;

    for (int num : left_vec) {
      if (num + val == target) ans++;
      vec.push_back(num + val);
    }

    for (int num : right_vec) {
      if (num + val == target) ans++;
      vec.push_back(num + val);
    }

    if (left_num != kNull) {
      if (val + left_num == target) ans++;
      vec.push_back(val + left_num);
    }
    if (right_num != kNull) {
      if (val + right_num == target) ans++;
      vec.push_back(val + right_num);
    }

    return {vec, val};
  }
  int pathSum(TreeNode* root, int targetSum) {
    target = targetSum;

    find(root);

    return ans;
  }
};