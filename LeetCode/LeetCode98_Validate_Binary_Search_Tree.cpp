// Approach: In-order traversal
// Time complexity: O(N)
// Space complexity: O(logN)
// N: number of tree nodes
class Solution {
    using LL = long long;
    LL lastNode = LLONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;

        bool left = isValidBST(root->left);

        bool parent = (LL)root->val > lastNode;
        lastNode = root->val;

        bool right = isValidBST(root->right);

        return left && right && parent;
    }
};

#include "./lib/BinaryTree.hpp"
#include <iostream>
#include <limits>
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
  enum Dir { Left, Mid, Right };
  const long long Min = numeric_limits<int>::min() - 1LL;
  const long long Max = numeric_limits<int>::max() + 1LL;
  pair<long long, long long> find(TreeNode* root, bool& result) {
    if (!result) return {Min, Max};

    if(root == nullptr)
        return {Max, Min};

    auto left = find(root->right, result);
    auto right = find(root->right, result);

    if(left.second >= root->val || right.first <= root->val) {
        result = false;
        return {Min, Max};
    }

    return {left.first, right.second};
  }
  bool isValidBST(TreeNode* root) {
    bool result = true;
    find(root, result);

    return result;
  }
};
*/
// Success
// Time complexity: O(n), Space complexity: O(depth of tree)
class Solution {
 public:
  bool find(TreeNode* root, long long start, long long end) {
    if (root == nullptr) return true;

    if (start >= root->val || end <= root->val) return false;

    auto left = find(root->left, start, root->val);
    auto right = find(root->right, root->val, end);

    return left && right;
  }
  bool isValidBST(TreeNode* root) {
    long long start = numeric_limits<int>::min() - 1LL;
    long long end = numeric_limits<int>::max() + 1LL;
    return find(root, start, end);
  }
};
  int main() {
    //BinaryTree bt("120,70,140,50,100,130,160,20,55,75,110,119,135,150,200");
    BinaryTree bt("2,1,3");
    Solution s;
    cout << s.isValidBST(bt.get_root());
  }