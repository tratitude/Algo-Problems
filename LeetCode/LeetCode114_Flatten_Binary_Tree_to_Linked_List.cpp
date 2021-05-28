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
// Time complexity: O(n), Space complexity: O(n)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        root->left = nullptr;
        root->right = left;
        
        TreeNode* ptr = root;
        while(ptr->right != nullptr){
            ptr = ptr->right;
        }
        ptr->right = right;
    }
};