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
  vector<TreeNode *> allPossibleFBT(int n) {
    if (n == 0) {
      return vector<TreeNode *>();
    } else if (n == 1) {
      return vector<TreeNode *>{new TreeNode(0)};
    }
    vector<TreeNode *> result;

    for (int i = 1; i < n; i += 2) {
      vector<TreeNode *> left = allPossibleFBT(i);
      vector<TreeNode *> right = allPossibleFBT(n - i - 1);
      for (const auto &l : left) {
        for (const auto &r : right) {
          TreeNode *root = new TreeNode(0);
          root->left = l;
          root->right = r;
          result.push_back(root);
        }
      }
    }
    return result;
  }
};
