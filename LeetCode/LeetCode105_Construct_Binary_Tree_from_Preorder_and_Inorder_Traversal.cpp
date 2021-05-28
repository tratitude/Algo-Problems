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
// Time complexity: O(n)
// Space complexity: 
//   Overall is O(n), create nodes is O(n), in function stack the best is O(log(n)) and the worst is O(n)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        reverse(preorder.begin(), preorder.end());
        return build(preorder, inorder, 0, preorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if(start > end)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder.back());
        preorder.pop_back();
        
        int rootPos = -1;
        for(int i=0; i<inorder.size(); ++i){
            if(root->val == inorder[i]){
                rootPos = i;
                break;
            }
        }
        
        root->left = build(preorder, inorder, start, rootPos-1);
        root->right = build(preorder, inorder, rootPos+1, end);
        
        return root;
    }
};