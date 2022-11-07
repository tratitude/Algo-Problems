// Time complexity: O(N)
// Space complexity: O(logN)
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(nums, 0, nums.size());
    }
    TreeNode* createBST(vector<int>& nums, int begin, int end) {
        if (begin >= end) return nullptr;
        if (begin+1 == end) return new TreeNode(nums[begin]);

        int mid = begin + (end - begin)/2;
        TreeNode* node = new TreeNode(nums[mid]);

        node->left = createBST(nums, begin, mid);
        node->right = createBST(nums, mid+1, end);

        return node;
    }
};