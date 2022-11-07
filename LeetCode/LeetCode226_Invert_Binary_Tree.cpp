// Time complexity: O(N)
// Space complexity: O(H)
// H: height of the tree
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;

        auto left = invertTree(root->left);
        auto right = invertTree(root->right);
        root->left = right;
        root->right = left;

        return root;
    }
};
/*
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/
// Time complexity: O(n), Space complexity: O(log(n))
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        
        invertTree(root->left);
        invertTree(root->right);
        
        if(root->left != nullptr || root->right != nullptr){
            swap(root->left, root->right);
        }
        return root;
    }
};

