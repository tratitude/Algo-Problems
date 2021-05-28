#include <vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void construct(vector<int>& nums, TreeNode* root, int rootPos, int start, int end){
    if(start > end)
        return;
    
    int maxNum = nums[start];
    int maxPos = start;
    for(int i=start+1; i<=end; ++i){
        if(nums[i] > maxNum){
            maxNum = nums[i];
            maxPos = i;
        }
    }
    TreeNode* newNode = new TreeNode;
    newNode->val = maxNum;
    if(maxPos < rootPos){
        root->left = newNode;
        construct(nums, newNode, maxPos, start, maxPos-1);
        construct(nums, newNode, maxPos, maxPos+1, rootPos-1);
    }
    else{
        root->right = newNode;
        construct(nums, newNode, maxPos, rootPos+1, maxPos-1);
        construct(nums, newNode, maxPos, maxPos+1, end);
    }
}
// Time complexity: O(n^2)
// Space complexity: 
//   Overall is O(n), create nodes is O(n), in function stack the best is O(log(n)) and the worst is O(n)
// 先sort另外存，Time complexity: O(nlog(n)), Space complexity: O(n)
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    int maxNum = nums[0], rootPos = 0;
    for(int i=1; i<nums.size(); ++i){
        if(nums[i] > maxNum){
            maxNum = nums[i];
            rootPos = i;
        }
    }
    TreeNode* root = new TreeNode;
    root->val = maxNum;
    TreeNode* ptr = root;
    construct(nums, ptr, rootPos, 0, rootPos-1);
    construct(nums, ptr, rootPos, rootPos+1, nums.size()-1);
    
    return root;
}

int main()
{
    vector<int> nums = {3,2,1,6,0,5};
    TreeNode* root = constructMaximumBinaryTree(nums);
}