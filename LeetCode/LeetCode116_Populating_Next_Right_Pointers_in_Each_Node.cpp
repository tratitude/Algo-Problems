// Time complexity: O(N)
// Space complexity: O(log(N))
// N: number of nodes
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) {
            return nullptr;
        }
        
        auto right = connect(root->right);
        auto left = connect(root->left);
        
        if(right != nullptr && left != nullptr) {
            left->next = right;
            while(left->right != nullptr && right->left != nullptr) {
                left = left->right;
                right = right->left;
                left->next = right;
            }
        }
        
        return root;
    }
};

// Time complexity: O(N)
// Space complexity: O(log(N))
// N: number of nodes
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return nullptr;
        
        Node* left = root->left;
        Node* right = root->right;
        while(left != nullptr && right != nullptr){
            left->next = right;
            left = left->right;
            right = right->left;
        }
        
        connect(root->right);
        connect(root->left);
        
        return root;
    }
};