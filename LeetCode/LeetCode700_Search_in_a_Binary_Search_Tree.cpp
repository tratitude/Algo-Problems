/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Time complexity: O(D), Space complexity: O(D)
// D: depth of the input binary search tree
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr)
            return nullptr;
        
        auto result = (TreeNode*)nullptr;
        
        if(val == root->val) {
            result = root;
        }
        else if(val < root->val) {
            auto left = searchBST(root->left, val);
            if(left != nullptr)
                result = left;
        }
        else {
            auto right = searchBST(root->right, val);
            if(right != nullptr)
                result = right;
        }
        
        return result;
    }
};