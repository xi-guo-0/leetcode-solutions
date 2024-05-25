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
  int longestUnivaluePath(TreeNode *root) {
    int result = 1;
    depth(root, -1, result);
    return result - 1;
  }

private:
  int depth(TreeNode *node, const int val, int &result) {
    if (node == nullptr) {
      return 0;
    }
    int L = depth(node->left, node->val, result);
    int R = depth(node->right, node->val, result);
    result = max(result, L + R + 1);
    return node->val == val ? max(L, R) + 1 : 0;
  }
};
