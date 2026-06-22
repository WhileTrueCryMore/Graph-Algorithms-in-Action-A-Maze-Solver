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
  bool hasPathSum(TreeNode* root, int targetSum) {
    return isSum(root, targetSum);
  }
  bool isSum(TreeNode* root, int target) {
    if (!root) {
      return false;
    }
    if (!root->left && !root->right && root->val == target) {
      return true;
    } else if (!root->left && !root->right)
      return false;

    return (isSum(root->left, target - root->val) || isSum(root->right, target - root->val));
  }
};