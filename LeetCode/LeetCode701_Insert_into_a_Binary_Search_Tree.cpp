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
// Time complexity: O(D), Space complexity: O(D)
// D: depth of the input binary search tree
class Solution {
 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
      root = new TreeNode;
      root->val = val;
      return root;
    }

    if (val < root->val) {
      if (root->left == nullptr) {
        root->left = new TreeNode;
        root->left->val = val;
        return root;
      } else {
        root->left = insertIntoBST(root->left, val);
      }
    } else if (val > root->val) {
      if (root->right == nullptr) {
        root->right = new TreeNode;
        root->right->val = val;
        return root;
      } else {
        root->right = insertIntoBST(root->right, val);
      }
    }

    return root;
  }
};