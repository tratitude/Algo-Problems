#include "lib/BinaryTree.hpp"
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
// Time complexity: O(log(n)), Space complexity: O(log(n))
// 想法: 遞迴到底，往回更新資訊。可用於刪除、插入等需要更新前後node
/*
TreeNode* f(TreeNode* root) {
  if(root == nullptr)
    return nullptr;
  
  root->left = f(root->left);
  root->right = f(root->right);
  return root;
}
*/
class Solution {
 public:
  TreeNode* getMin(TreeNode* root) {
    while (root->left) root = root->left;
    return root;
  }
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;

    if (root->val == key) {
      if (!root->left) return root->right;
      if (!root->right) return root->left;

      auto node = getMin(root->right);
      root->val = node->val;
      root->right = deleteNode(root->right, node->val);
    } else if (key < root->val) {
      root->left = deleteNode(root->left, key);
    } else {
      root->right = deleteNode(root->right, key);
    }

    return root;
  }
};

int main()
{
  BinaryTree bt("5,3,6,2,4,null,7");
  bt.inorder();
  Solution sol;
  sol.deleteNode(bt.get_root(), 3);
  bt.inorder();
}