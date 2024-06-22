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
  int rangeSumBST(TreeNode *root, int L, int R) {
    if (!root)
      return 0;
    int root_val = root->val;
    int left_val = 0;
    int right_val = 0;
    if (root_val < L || root_val > R)
      root_val = 0;
    if (root->left)
      left_val = rangeSumBST(root->left, L, R);
    if (root->right)
      right_val = rangeSumBST(root->right, L, R);
    return root_val + left_val + right_val;
  }
};
