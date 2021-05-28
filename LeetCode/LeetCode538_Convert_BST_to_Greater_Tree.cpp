/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// Time complexity: O(n), Space complexity: O(log(n)) ~ O(n)
class Solution {
 public:
  int sum = 0;
  void dfs(TreeNode* root) {
    if (!root) return;
    dfs(root->right);

    auto tmp = root->val;
    root->val += sum;
    sum += tmp;

    dfs(root->left);
  }
  TreeNode* convertBST(TreeNode* root) {
    auto ptr = root;
    dfs(ptr);
    return root;
  }
};