// Time complexity: O(N)
// Space complexity: O(M)
// M: depth of the tree
class Solution {
    vector<int> path;
    vector<vector<int>> ans;
    int target = 0;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return {};

        target = targetSum;

        bt(root);
        return ans;
    }
    void bt(TreeNode* root) {
        path.push_back(root->val);
        target -= root->val;

        if (root->left) bt(root->left);
        if (root->right) bt(root->right);

        if (root->left == nullptr && root->right == nullptr && target == 0) {
            ans.push_back(path);
        }

        target += path.back();
        path.pop_back();
    }
};
// Time complexity: O(N)
// Space complexity: O(M)
// M: depth of the tree
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};

        vector<vector<int>> ans;
        vector<int> path;
        stack<TreeNode*> st;
        st.push(nullptr);
        st.push(root);

        while (!empty(st)) {
            TreeNode* node = st.top(); st.pop();
            if (!node) {
                targetSum += path.back();
                path.pop_back();
            } else {
                path.push_back(node->val);
                targetSum -= node->val;
                if (!node->left && !node->right && !targetSum) {
                    ans.push_back(path);
                }
                if (node->left) {
                    st.push(nullptr);
                    st.push(node->left);
                }
                if (node->right) {
                    st.push(nullptr);
                    st.push(node->right);
                }
            }
        }
        
        return ans;
    }
};