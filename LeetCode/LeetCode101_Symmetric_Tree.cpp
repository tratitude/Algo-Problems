// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> leftQueue, rightQueue;

        leftQueue.push(root->left);
        rightQueue.push(root->right);

        while (!leftQueue.empty() && !rightQueue.empty()) {
            auto left = leftQueue.front();
            leftQueue.pop();
            auto right = rightQueue.front();
            rightQueue.pop();

            if (left == nullptr && right == nullptr) continue;
            if (left == nullptr || right == nullptr) return false;
            if (left->val != right->val) return false;

            leftQueue.push(left->left);
            rightQueue.push(right->right);
            leftQueue.push(left->right);
            rightQueue.push(right->left);
        }
        return true;
    }
};
// Time complexity: O(N)
// Space complexity: O(M)
// M: depth of the tree
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return comp(root->left, root->right);
    }
    bool comp(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        if (p->val != q->val) return false;
        return comp(p->left, q->right) && comp(p->right, q->left);
    }
};