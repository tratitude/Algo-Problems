// Time complexity: O(N)
// Space complexity: O(logN) for balanced tree, O(N) for unbalanced tree
class Solution {
    int ans = -1, cnt = -1;
public:
    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        traverse(root);
        return ans;
    }
    void traverse(TreeNode* root) {
        if (root == nullptr) return;

        traverse(root->left);

        if (--cnt == 0)
            ans = root->val;
        
        traverse(root->right);
    }
};
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
// Time complexity: O(logN + k) for balanced tree, O(N + k) for unbalanced tree
// Space complexity: O(logN) for balanced tree, O(N) for unbalanced tree
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