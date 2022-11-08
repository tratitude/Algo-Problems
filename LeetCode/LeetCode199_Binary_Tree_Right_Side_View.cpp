// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        queue<pair<int, TreeNode*>> q;
        vector<int> ans;
        int maxDepth = -1;

        q.push({0, root});

        while (q.size() > 0) {
            auto [depth, node] = q.front();
            q.pop();

            if (depth > maxDepth) {
                maxDepth = depth;
                ans.push_back(node->val);
            }
            if (node->right) q.push({depth + 1, node->right});
            if (node->left) q.push({depth + 1, node->left});
        }
        return ans;
    }
};