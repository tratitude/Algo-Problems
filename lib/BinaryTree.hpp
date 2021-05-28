#pragma once
#ifndef BINARY_TREE
#define BINARY_TREE

#include <string>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class BinaryTree {
 public:
  BinaryTree(std::string nodeString)
      : _nodeString(nodeString), _root(new TreeNode) {
    parseNode();
    createBinaryTree();
  };
  BinaryTree(std::string nodeString, int p, int q)
      : _nodeString(nodeString), _root(new TreeNode) {
    parseNode();
    createBinaryTree(p, q);
  };
  void parseNode();
  void createBinaryTree();
  void createBinaryTree(int, int);
  TreeNode *get_root();
  TreeNode *get_p();
  TreeNode *get_q();
  void inorder();
  void preorder();
  void postorder();

 private:
  std::string _nodeString;
  std::vector<std::string> _nodes;
  TreeNode *_root;
  TreeNode* _p;
  TreeNode* _q;
};

#endif