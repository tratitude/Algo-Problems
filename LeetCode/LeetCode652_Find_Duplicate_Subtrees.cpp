/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Time complexity: O(nlog(n)), Space complexity: O(n)
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, int> subTree;
        vector<TreeNode*> dup;
        encode(root, subTree, dup);
        return dup;
    }
    string encode(TreeNode* root, map<string, int>& subTree, vector<TreeNode*>& dup){
        if(root == nullptr)
            return "#";
        
        ostringstream os;
        os << root->val << ","
            << encode(root->left, subTree, dup) << ","
            << encode(root->right, subTree, dup);
        
        string id = os.str();
        if(++subTree[id] == 2)
            dup.push_back(root);
        
        return id;
    }
};
// 看不懂hash為何能正確
/*
struct TreeInfo{
    TreeNode *left;      //Representative of left subtree eq-class
    TreeNode *right;    //Representative of right subtree eq-class
    int val;
};

template <>
class hash<TreeInfo> {
    public:
    size_t operator()(const TreeInfo &info) const {
        return (reinterpret_cast<size_t>(info.left) >> 2)
            ^ (reinterpret_cast<size_t>(info.right) >> 1) ^ info.val;
    }
};

bool operator==(const TreeInfo &ti1, const TreeInfo &ti2) {
    return ti1.left == ti2.left && ti1.right == ti2.right && ti1.val == ti2.val;
}
bool operator!=(const TreeInfo &ti1, const TreeInfo &ti2) {
    return !(ti1==ti2);
}

class Solution {
public:
    TreeNode *recDupSubTrees(TreeNode *root, unordered_set<TreeNode*> &answer,
                          unordered_map<TreeInfo, TreeNode*> &eqClass) {
        
        TreeNode *leftEqClass = nullptr, *rightEqClass=nullptr;
        if(root->left)
            leftEqClass = recDupSubTrees(root->left, answer, eqClass);
        if(root->right)
            rightEqClass = recDupSubTrees(root->right, answer, eqClass);
        TreeInfo treeInfo{ leftEqClass, rightEqClass, root->val};

		// Have we seen a copy of this subtree before?
		// If not, we store a pointer to its root in the map, 
		// indexed by our description of the subtree.
		// If we have seen this subtree before, we add 
		// it to the set of subtrees which have a duplicate (our answer)
        if(eqClass.find(treeInfo) == eqClass.end())
            eqClass[treeInfo] = root;
        else
            answer.insert(eqClass[treeInfo]);
        return eqClass[treeInfo];
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_set<TreeNode*> answer;
        unordered_map< TreeInfo, TreeNode * > eqClass;
        recDupSubTrees(root, answer, eqClass);
        return vector<TreeNode*>(answer.begin(), answer.end());
    }
};
*/