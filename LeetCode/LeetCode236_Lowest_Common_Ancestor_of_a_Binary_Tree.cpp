// Time complexity: O(N)
// Space complexity: O(M)
// N: number of nodes
// M: max depth of tree
class Solution {
  TreeNode* ans = nullptr;
  int p_val, q_val;

 public:
  bool find(TreeNode* root) {
    if (root == nullptr) {
      return false;
    }

    int found = 0;
    bool ret = false;
    if (root->val == p_val || root->val == q_val) {
      ++found;
    }
    if (find(root->left)) {
      ++found;
    }
    if (find(root->right)) {
      ++found;
    }

    if (found == 2) {
      ans = root;
    } else if (found == 1) {
      ret = true;
    }

    return ret;
  }
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    p_val = p->val;
    q_val = q->val;

    find(root);

    return ans;
  }
};

// Time complexity: O(N)
// Space complexity: O(M)
// N: number of nodes
// M: max depth of tree
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