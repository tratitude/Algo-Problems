// Time complexity: O(N*M)
// Space complexity: O(K)
// N: number of nodes in root
// M: number of nodes in subRoot
// K: max depth of root
class Solution {
 public:
  bool check(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr || subRoot == nullptr) {
      return root == subRoot;
    }

    if (root->val != subRoot->val) {
      return false;
    }

    return check(root->left, subRoot->left) &&
           check(root->right, subRoot->right);
  }
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr) {
      return false;
    }

    if (root->val == subRoot->val) {
      if (check(root, subRoot)) {
        return true;
      }
    }

    if (isSubtree(root->left, subRoot)) {
      return true;
    }
    if (isSubtree(root->right, subRoot)) {
      return true;
    }

    return false;
  }
};