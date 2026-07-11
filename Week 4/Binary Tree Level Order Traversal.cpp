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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> a;
    if (!root) return ans;
    a.push(root);
    while (!a.empty()) {
      int s = a.size();
      vector<int> curr;
      while (s--) {
        TreeNode* n = a.front();
        a.pop();
        curr.push_back(n->val);
        if (n->left) a.push(n->left);
        if (n->right) a.push(n->right);
      }
      ans.push_back(curr);
    }
    return ans;
  }
};