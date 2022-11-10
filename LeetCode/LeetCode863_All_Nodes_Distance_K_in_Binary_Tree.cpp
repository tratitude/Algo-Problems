// Approach: BFS

// Time complexity: O(N)
// Space complexity: O(M)
// M: depth of the tree
class Solution {
    TreeNode* Target = nullptr;
    int K = 0;
    vector<int> ans;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        Target = target;
        K = k;

        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root) {
        if (root == nullptr) return -1;
        if (root == Target) {
            findSubtree(root, K);
            return 1;
        }

        int left = dfs(root->left), right = dfs(root->right);
        int dist = -1;
        if (left != -1) {
            findSubtree(root->right, K - left - 1);
            if (left == K)
                ans.push_back(root->val);
            dist = left + 1;
        } else if (right != -1) {
            findSubtree(root->left, K - right - 1);
            if (right == K)
                ans.push_back(root->val);
            dist = right + 1;
        }
        return dist;
    }
    void findSubtree(TreeNode* root, int dist) {
        if (dist < 0 || root == nullptr) return;
        if (dist == 0) {
            ans.push_back(root->val);
            return;
        }
        findSubtree(root->left, dist - 1);
        findSubtree(root->right, dist - 1);
    }
};