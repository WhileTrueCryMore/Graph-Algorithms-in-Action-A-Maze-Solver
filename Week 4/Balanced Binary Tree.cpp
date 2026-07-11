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
class Solution {
 public:
  bool is = 0;
  bool isBalanced(TreeNode* root) {
    depth(root);
    return (!is);
  }

  int depth(TreeNode* root) {
    if (is) return 0;
    if (!root) {
      return 0;
    }
    int ll = depth(root->left);
    if (is) return 0;
    int rl = depth(root->right);
    if (is) return 0;
    if (abs(ll - rl) > 1) {
      is = 1;
      return 0;
    }
    return 1 + max(ll, rl);
  }
};