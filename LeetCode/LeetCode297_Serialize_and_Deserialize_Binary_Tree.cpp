/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:
  void encode(TreeNode* root, ostringstream& os) {
    if (root == nullptr) {
      os << "# ";
      return;
    }

    os << root->val << " ";

    encode(root->left, os);
    encode(root->right, os);
  }
  TreeNode* decode(istringstream& in) {
    string val;
    in >> val;

    if (val == "#") return nullptr;

    auto root = new TreeNode(stoi(val));
    root->left = decode(in);
    root->right = decode(in);

    return root;
  }
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    ostringstream os;
    encode(root, os);
    return os.str();
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream is(data);
    return decode(is);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));