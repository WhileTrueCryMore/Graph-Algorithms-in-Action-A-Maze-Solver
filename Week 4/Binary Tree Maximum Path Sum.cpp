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
  int mx = INT_MIN;
  int pathdown(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int l = pathdown(root->left);
    int r = pathdown(root->right);
    int su = max(max(l, r) + root->val, root->val);
    int s = max(su, l + r + root->val);
    mx = max(mx, s);
    return su;
  }

 public:
  int maxPathSum(TreeNode* root) {
    pathdown(root);
    return mx;
  }
};