/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  int rob(TreeNode *root) {
    int temp{};
    return solve(root, temp);
  }

private:
  int solve(TreeNode *p, int &c) {
    if (!p)
      return 0;
    int l{}, r{};
    c = solve(p->left, l) + solve(p->right, r);
    return max(l + r + p->val, c);
  }
};
