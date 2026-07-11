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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int s = q.size();
      int curr = 0;
      while (s--) {
        TreeNode* n = q.front();
        q.pop();
        if (s == 0) curr = n->val;
        if (n->left) {
          q.push(n->left);
        }
        if (n->right) {
          q.push(n->right);
        }
      }
      ans.push_back(curr);
    }
    return ans;
  }
};