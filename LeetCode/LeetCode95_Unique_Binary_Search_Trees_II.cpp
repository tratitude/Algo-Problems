#include <vector>

#include "./lib/BinaryTree.hpp"

using namespace std;
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
/*
class Solution {
 public:
  vector<TreeNode *> generateTrees(int n) {
      auto table = new vector<TreeNode*>*[n+1];
      for(int i=0; i<=n; ++i)
        table[i] = new vector<TreeNode*>[n+1];

      return build(1, n, table);
    }
  vector<TreeNode *> build(int lo, int hi, vector<TreeNode*> **table) {
    vector<TreeNode *> res;
    if (lo > hi) {
      res.push_back((TreeNode *)nullptr);
      return res;
    }

    if(!table[lo][hi].empty()) {
      vector<TreeNode*> cp;
      copyTable(table[lo][hi], cp);
      return cp;
    }

    for (int i = lo; i <= hi; ++i) {
      auto leftTree = build(lo, i - 1, table);
      auto rightTree = build(i + 1, hi, table);

      for (auto left : leftTree) {
        for (auto right : rightTree) {
          auto root = new TreeNode(i);
          root->left = left;
          root->right = right;
          res.push_back(root);
        }
      }
    }
    table[lo][hi] = move(res);

    return table[lo][hi];
  }
  void copyTable(const vector<TreeNode*> &in, vector<TreeNode*> &out) {
    for(const auto& root : in) {
      TreeNode* outRoot;
      traverse(root, outRoot);
      out.push_back(outRoot);
    }
  }
  TreeNode* traverse(const TreeNode* inRoot, TreeNode* outRoot) {
    if(inRoot == nullptr)
      return nullptr;
    
    outRoot = new TreeNode(inRoot->val);

    outRoot->left = traverse(inRoot->left, outRoot->left);
    outRoot->right = traverse(inRoot->right, outRoot->right);

    return outRoot;
  }
};

int main() {
  Solution sol;
  sol.generateTrees(5);
}
*/
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
class Solution {
 public:
  vector<TreeNode*> generateTrees(int n) { return build(1, n); }
  vector<TreeNode*> build(int lo, int hi) {
    vector<TreeNode*> res;
    if (lo > hi) {
      res.push_back((TreeNode*)nullptr);
      return res;
    }

    for (int i = lo; i <= hi; ++i) {
      auto leftTree = build(lo, i - 1);
      auto rightTree = build(i + 1, hi);

      for (auto left : leftTree) {
        for (auto right : rightTree) {
          auto root = new TreeNode(i);
          root->left = left;
          root->right = right;
          res.push_back(root);
        }
      }
    }
    return res;
  }
};