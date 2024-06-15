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
  TreeNode *increasingBST(TreeNode *root) {
    vector<TreeNode *> result;
    TreeNode dummy(-1);
    TreeNode *cur = root, *prev = nullptr;
    while (cur != nullptr) {
      if (cur->left == nullptr) {
        result.push_back(cur);
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
          result.push_back(cur);
          node->right = nullptr;
          prev = cur;
          cur = cur->right;
        }
      }
    }
    cur = &dummy;
    for (auto &n : result) {
      cur->right = n;
      cur = cur->right;
      cur->left = nullptr;
    }
    return dummy.right;
  }
};
