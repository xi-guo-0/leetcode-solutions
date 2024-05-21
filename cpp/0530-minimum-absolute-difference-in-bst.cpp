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
private:
  int min = INT_MAX;
  int *prev = nullptr;

public:
  int getMinimumDifference(TreeNode *root) {
    if (nullptr == root) {
      return min;
    }
    getMinimumDifference(root->left);
    if (nullptr != prev) {
      min = std::min(min, root->val - *prev);
    }
    prev = &root->val;
    getMinimumDifference(root->right);
    return min;
  }
};
