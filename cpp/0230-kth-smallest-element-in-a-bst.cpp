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
  int kthSmallest(TreeNode *root, int k) {
    vector<int> result;
    TreeNode *cur = root, *prev = nullptr;
    while (cur != nullptr) {
      if (cur->left == nullptr) {
        result.push_back(cur->val);
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
          result.push_back(cur->val);
          node->right = nullptr;
          prev = cur;
          cur = cur->right;
        }
      }
    }
    return result[k - 1];
  }
};
