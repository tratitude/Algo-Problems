// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        queue<pair<int, TreeNode*>> q;
        vector<vector<int>> ans = {{root->val}};

        if (root->left != nullptr) q.push({2, root->left});
        if (root->right != nullptr) q.push({2, root->right});

        while (q.size() > 0) {
            auto [level, node] = q.front();
            q.pop();

            if (level > ans.size()) {
                ans.push_back({node->val});
            } else {
                ans.back().push_back(node->val);
            }
            if (node->left != nullptr) q.push({level+1, node->left});
            if (node->right != nullptr) q.push({level+1, node->right});
        }
        return ans;
    }
};