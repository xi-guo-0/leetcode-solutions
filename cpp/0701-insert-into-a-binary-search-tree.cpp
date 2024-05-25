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
public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    TreeNode *node = new TreeNode(val);
    TreeNode *prev = nullptr, *cur = root;
    if (root == nullptr) {
      return node;
    }
    while (cur != nullptr) {
      prev = cur;
      if (val < cur->val)
        cur = cur->left;
      else
        cur = cur->right;
    }
    if (val < prev->val)
      prev->left = node;
    else
      prev->right = node;
    return root;
  }
};
