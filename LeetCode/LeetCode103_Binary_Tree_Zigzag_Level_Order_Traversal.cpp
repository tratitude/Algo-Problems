// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> ans;
        deque<TreeNode*> q;
        bool left2right = true;

        q.push_back(root);

        while (!q.empty()) {
            vector<int> order;
            if (left2right) {
                for (auto node : q)
                    order.push_back(node->val);
            } else {
                for (auto it = q.rbegin(); it != q.rend(); it++)
                    order.push_back((*it)->val);
            }
            ans.push_back(order);
            left2right ^= true;

            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                auto node = q.front();
                q.pop_front();
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
        }
        return ans;
    }
};