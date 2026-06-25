/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  unordered_map<int, int> pos;

  TreeNode* buildSub(vector<int>& preorder, int pl, int pr, int il, int ir) {
    if (pl > pr)
      return nullptr;

    int rootVal = preorder[pl];
    int rootIdx = pos[rootVal];

    TreeNode* root = new TreeNode(rootVal);

    int leftSize = rootIdx - il;

    root->left = buildSub(preorder, pl + 1, pl + leftSize, il, rootIdx - 1);

    root->right =
        buildSub(preorder, pl + leftSize + 1, pr, rootIdx + 1, ir);

    return root;
  }

 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); i++) {
      pos[inorder[i]] = i;
    }

    return buildSub(preorder, 0, preorder.size() - 1, 0,
                    inorder.size() - 1);
  }
};