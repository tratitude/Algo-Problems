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
// Time complexity: O(n), Space complexity: O(n)
class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    int result = 0;
    stack<TreeNode*> tree;
    auto head = root;

    while (head != nullptr || !tree.empty()) {
      while (head != nullptr) {
        tree.push(head);
        head = head->left;
      }

      head = tree.top();
      tree.pop();

      if (--k == 0) {
        result = head->val;
        break;
      }

      head = head->right;
    }
    return result;
  }
};