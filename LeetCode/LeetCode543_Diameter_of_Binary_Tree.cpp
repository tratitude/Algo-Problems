// Time complexity: O(N)
// Space complexity: O(M)
// M: max depth of the tree
class Solution {
    int ans = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return ans;
    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        ans = ans < left + right ? left + right : ans;

        return max(left, right) + 1;
    }
};