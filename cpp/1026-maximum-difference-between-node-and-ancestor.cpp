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
  int maxAncestorDiff(TreeNode *root) {
    if (root == nullptr)
      return 0;
    return maxAncestorDiff(root, root->val, root->val);
  }

private:
  int maxAncestorDiff(TreeNode *root, int low, int high) {
    int result = max(abs(root->val - low), abs(root->val - high));
    if (root != nullptr) {
      if (root->left != nullptr)
        result = max(result, maxAncestorDiff(root->left, min(low, root->val),
                                             max(high, root->val)));
      if (root->right != nullptr)
        result = max(result, maxAncestorDiff(root->right, min(low, root->val),
                                             max(high, root->val)));
    }
    return result;
  }
};
