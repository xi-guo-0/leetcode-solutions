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
  int result;
  int distributeCoins(TreeNode *root) {
    result = 0;
    dfs(root);
    return result;
  }

private:
  int dfs(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int L = dfs(root->left);
    int R = dfs(root->right);
    result += abs(L) + abs(R);
    return root->val + L + R - 1;
  }
};
