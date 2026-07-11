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
 private:
  int curr = 0;
  int val = 0;
  void inorder(TreeNode* root, int target) {
    if (!root || target <= curr) return;
    inorder(root->left, target);
    if (++curr == target) {
      val = root->val;
      return;
    }
    inorder(root->right, target);
    return;
  }

 public:
  int kthSmallest(TreeNode* root, int k) {
    inorder(root, k);
    return val;
  }
};