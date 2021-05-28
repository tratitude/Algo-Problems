#include "BinaryTree.hpp"

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>


void BinaryTree::parseNode() {
  int head = 0;
  _nodeString.push_back(',');
  for (int i = 0; i < _nodeString.size(); ++i) {
    if (_nodeString[i] == ',') {
      std::string node(_nodeString.begin() + head, _nodeString.begin() + i);
      _nodes.push_back(node);
      head = i + 1;
    }
  }
}

void BinaryTree::createBinaryTree() {
  std::queue<TreeNode *> bfs;
  bfs.push(_root);

  for (int i = 0; i < _nodes.size(); ++i) {
    if (_nodes[i] == "null") continue;
    auto node = bfs.front();
    bfs.pop();
    node->val = std::stoi(_nodes[i]);
    if (i * 2 + 1 < _nodes.size() && _nodes[i * 2 + 1] != "null") {
      auto left = new TreeNode;
      node->left = left;
      bfs.push(left);
    }
    if (i * 2 + 2 < _nodes.size() && _nodes[i * 2 + 2] != "null") {
      auto right = new TreeNode;
      node->right = right;
      bfs.push(right);
    }
  }
}

void BinaryTree::createBinaryTree(int p, int q) {
  std::queue<TreeNode *> bfs;
  bfs.push(_root);

  for (int i = 0; i < _nodes.size(); ++i) {
    if (_nodes[i] == "null") continue;
    auto node = bfs.front();
    bfs.pop();
    node->val = std::stoi(_nodes[i]);

    if(node->val == p)
      _p = node;
    else if(node->val == q)
      _q = node;

    if (i * 2 + 1 < _nodes.size() && _nodes[i * 2 + 1] != "null") {
      auto left = new TreeNode;
      node->left = left;
      bfs.push(left);
    }
    if (i * 2 + 2 < _nodes.size() && _nodes[i * 2 + 2] != "null") {
      auto right = new TreeNode;
      node->right = right;
      bfs.push(right);
    }
  }
}

TreeNode *BinaryTree::get_root() { return _root; }
TreeNode *BinaryTree::get_p() { return _p; };
TreeNode *BinaryTree::get_q(){ return _q; };
void BinaryTree::inorder() {
  std::cout << "In Order: ";

  std::stack<TreeNode *> tree;
  auto cur = _root;

  while (cur != nullptr || !tree.empty()) {
    // left subtree
    while (cur != nullptr) {
      tree.push(cur);
      cur = cur->left;
    }
    cur = tree.top();
    tree.pop();

    // _root
    std::cout << cur->val << " ";

    // right subtree
    cur = cur->right;
  }
  std::cout << "\n";
}

void BinaryTree::preorder() {
  std::cout << "Pre Order: ";

  std::stack<TreeNode *> tree;
  auto cur = _root;

  while (cur != nullptr || !tree.empty()) {
    // _root
    if (cur != nullptr) std::cout << cur->val << " ";

    // left subtree
    if (cur != nullptr) {
      tree.push(cur);
      cur = cur->left;
      continue;
    }
    cur = tree.top();
    tree.pop();

    // right subtree
    cur = cur->right;
  }
  std::cout << "\n";
}

void BinaryTree::postorder() {
  std::cout << "Post Order: ";

  std::stack<TreeNode *> tree;
  auto cur = _root;

  while (cur != nullptr || !tree.empty()) {
    // left subtree
    while (cur != nullptr) {
      if (cur->right != nullptr) tree.push(cur->right);
      tree.push(cur);
      cur = cur->left;
    }
    cur = tree.top();
    tree.pop();

    // right subtree
    if (cur->right != nullptr && !tree.empty() && cur->right == tree.top()) {
      tree.pop();
      tree.push(cur);
      cur = cur->right;
      continue;
    }

    // _root
    std::cout << cur->val << " ";
    cur = nullptr;
  }
  std::cout << "\n";
}