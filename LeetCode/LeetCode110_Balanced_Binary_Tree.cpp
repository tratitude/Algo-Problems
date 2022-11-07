// Time complexity: O(N)
// Space complexity: O(H)
// H: height of the tree
class Solution {
    bool ans = true;
public:
    bool isBalanced(TreeNode* root) {
        maxHeight(root, 0);
        return ans;
    }
    int maxHeight(TreeNode* root, int h) {
        if (root == nullptr) return h-1;
        
        int left = maxHeight(root->left, h+1);
        int right = maxHeight(root->right, h+1);

        ans &= abs(left - right) < 2;
        return max(left, right);
    }
};