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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size()-1);
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int start, int end){
        if(start > end)
            return nullptr;
        
        TreeNode* root = new TreeNode(postorder.back());
        postorder.pop_back();
        int rootPos = -1;
        for(int i=0; i<inorder.size(); ++i){
            if(root->val == inorder[i]){
                rootPos = i;
                break;
            }
        }
        
        root->right = build(inorder, postorder, rootPos+1, end);
        root->left = build(inorder, postorder, start, rootPos-1);
        
        return root;
    }
};