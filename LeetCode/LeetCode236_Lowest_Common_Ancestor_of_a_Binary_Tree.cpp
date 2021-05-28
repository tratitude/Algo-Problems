/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
  TreeNode* res = nullptr;

 public:
  bool find(TreeNode* root, TreeNode* p, TreeNode* q) {
    bool ret = false;
    if (root == nullptr) return ret;

    auto findLeft = find(root->left, p, q);
    auto findRight = find(root->right, p, q);

    bool findRoot = false;
    if (root->val == p->val || root->val == q->val) findRoot = true;

    if (findLeft && findRight || findRoot && findLeft || findRoot && findRight)
      res = root;
    else
      ret = findRoot || findLeft || findRight;

    return ret;
  }
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    find(root, p, q);
    return res;
  }
};