// hash map approach
// Time complexity: O(n)
// Space complexity:
//   Overall is O(n), create nodes is O(n), in function stack the best is
//   O(log(n)) and the worst is O(n)
class Solution {
    int cnt = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIdx;
        for (int i = 0; i < inorder.size(); i++)
            inorderIdx[inorder[i]] = i;

        return build(preorder, inorderIdx, 0, inorder.size());
    }
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inorderIdx, int begin, int end) {
        if (begin == end) return nullptr;
        if (begin + 1 == end) return new TreeNode(preorder[cnt++]);

        int value = preorder[cnt++];
        auto node = new TreeNode(value);
        node->left = build(preorder, inorderIdx, begin, inorderIdx[value]);
        node->right = build(preorder, inorderIdx, inorderIdx[value] + 1, end);

        return node;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// Time complexity: O(n^2)
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
// hash map approach
// Time complexity: O(n)
// Space complexity:
//   Overall is O(n), create nodes is O(n), in function stack the best is
//   O(log(n)) and the worst is O(n)
class Solution {
 public:
  TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inMap,
                  int left, int right) {
    if (left > right) return nullptr;

    auto node = new TreeNode(preorder.back());
    preorder.pop_back();

    node->left = build(preorder, inMap, left, inMap[node->val] - 1);
    node->right = build(preorder, inMap, inMap[node->val] + 1, right);

    return node;
  }
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    reverse(preorder.begin(), preorder.end());
    // inorder[i] -> i
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); ++i) {
      inMap[inorder[i]] = i;
    }

    return build(preorder, inMap, 0, preorder.size() - 1);
  }
};