// Time complexity: O(logN)
// Space complexity: O(1)
// N: size of tree nodes
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) {
            if (root->val > max(p->val, q->val))
                root = root->left;
            else if (root->val < min(p->val, q->val))
                root = root->right;
            else
                break;
        }
        return root;
    }
};
// Time complexity: O(N)
// Space complexity: O(logN)
// N: size of tree nodes
class Solution {
    TreeNode* ans = nullptr;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        hasTarget(root, p, q);
        return ans;
    }
    bool hasTarget(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool left = hasTarget(root->left, p, q);
        bool right = hasTarget(root->right, p, q);
        bool parent = root == p || root == q;
        if (ans == nullptr) {
            if ((left && right) || (right && parent) || (left && parent)) {
                ans = root;
            }
        }
        return parent || left || right;
    }
};