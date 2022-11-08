// Approach: Post-order traversal to find a subtree that has maximum path sum
// - subtree type
//     - root
//     - root + max left subtree
//     - root + max right subtree
//     - root + max left subtree + max right subtree
// Time complexity: O(N)
// Space complexity: O(M)
// M: depth of the tree
class Solution {
    int ans = 0;
public:
    int maxPathSum(TreeNode* root) {
        ans = root->val;
        findMax(root);
        return ans;
    }
    int findMax(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = findMax(root->left);
        int right = findMax(root->right);
        int maxLR = max(left, right);
        int maxSubTree = maxLR < 0 ? root->val : maxLR + root->val;
        ans = max(ans, max(maxSubTree, left + right + root->val));

        return maxSubTree;
    }
};