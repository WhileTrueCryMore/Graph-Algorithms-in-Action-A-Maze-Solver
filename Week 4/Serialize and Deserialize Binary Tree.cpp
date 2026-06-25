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
  string code;
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {  // preorder
    if (!root) {
      code += "*,";
      return code;
    } else {
      code += to_string(root->val) + ',';
    }
    serialize(root->left);
    serialize(root->right);
    return code;
  }
  int idx = 0;
  // Decodes your encoded data to tree.
  TreeNode* deserialize(const string& data) {
    string token;

    while (data[idx] != ',') {
      token += data[idx];
      idx++;
    }
    idx++;
    if (token == "*") {
      return nullptr;
    }
    int val = stoi(token);
    TreeNode* root = new TreeNode(val);
    root->left = deserialize(data);
    root->right = deserialize(data);
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));