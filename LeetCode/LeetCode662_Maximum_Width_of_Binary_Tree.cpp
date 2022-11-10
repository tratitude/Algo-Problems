// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // node, num
        queue<pair<TreeNode*, long long>> q;
        int ans = 0;

        // num is zero-based
        q.push({root, 0});

        while (!q.empty()) {
            int levelNodes = q.size();
            long long beginNodeNum = q.front().second, endNodeNum = q.back().second;
            ans = max(ans, static_cast<int>(endNodeNum - beginNodeNum + 1));

            for (int i = 0; i < levelNodes; i++) {
                auto [node, num] = q.front();
                q.pop();
                int idx = num - beginNodeNum;

                if (node->left) q.push({node->left, (long long)idx*2 + 1});
                if (node->right) q.push({node->right, (long long)idx*2 + 2});
            }
        }

        return ans;
    }
};