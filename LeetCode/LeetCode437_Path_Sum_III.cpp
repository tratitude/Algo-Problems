// Backtracking with prefix sum approach
// Time complexity: O(N)
// Space complexity: O(M)
// N: number of nodes
// M: max depth of tree


// Time complexity: O(N^2)
// Space complexity: O(N^2)
// N: number of nodes
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