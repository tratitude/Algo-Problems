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
// Time complexity: O(n)
// Space complexity: O(depth of binary tree)
class Solution {
  int maxNum = 0;
  // [0]: 0 is not BST, 1 is BST, 2 is null
  // [1]: sum of subtree
  // [2]: min value of subtree
  // [3]: max value of subtree
  using ARR = array<int, 4>;

 public:
  ARR find(TreeNode* root) {
    ARR res;
    if (root == nullptr) {
      res = {2, 0, 0, 0};
      return res;
    }

    auto left = find(root->left);
    auto right = find(root->right);

    // if root is BST and both with child
    if (left[0] == 1 && right[0] == 1 && root->val > left[3] &&
        root->val < right[2]) {
      int val = root->val;
      int num = val + left[1] + right[1];
      res = {1, num, left[2], right[3]};
      maxNum = max(maxNum, num);
    }
    // if root is BST and with left child
    else if (left[0] == 1 && right[0] == 2 && root->val > left[3]) {
      int val = root->val;
      int num = val + left[1];
      res = {1, num, left[2], val};
      maxNum = max(maxNum, num);
    }
    // if root is BST and with right child
    else if (left[0] == 2 && right[0] == 1 && root->val < right[2]) {
      int val = root->val;
      int num = val + right[1];
      res = {1, num, val, right[3]};
      maxNum = max(maxNum, num);
    }
    // if root is leaf
    else if (left[0] == 2 && right[0] == 2) {
      int val = root->val;
      res = {1, val, val, val};
      maxNum = max(maxNum, val);
    }
    // if root is not BST
    else {
      res = {0, 0, 0, 0};
    }

    return res;
  }
  int maxSumBST(TreeNode* root) {
    find(root);
    return maxNum;
  }
};