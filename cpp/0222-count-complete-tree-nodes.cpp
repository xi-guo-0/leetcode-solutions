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
  int countNodes(TreeNode *root) {
    int result = 0;
    TreeNode *cur = root, *prev = nullptr;
    while (cur != nullptr) {
      if (cur->left == nullptr) {
        result++;
        prev = cur;
        cur = cur->right;
      } else {
        TreeNode *node = cur->left;
        while (node->right != nullptr && node->right != cur)
          node = node->right;

        if (node->right == nullptr) {
          node->right = cur;
          cur = cur->left;
        } else {
          result++;
          node->right = nullptr;
          prev = cur;
          cur = cur->right;
        }
      }
    }
    return result;
  }
};
