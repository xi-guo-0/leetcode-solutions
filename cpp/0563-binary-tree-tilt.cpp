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
  int sum = 0;

public:
  int findTilt(TreeNode *root) {
    if (nullptr == root) {
      return 0;
    }
    return std::abs(findSum(root->left) - findSum(root->right)) +
           findTilt(root->left) + findTilt(root->right);
  }

private:
  int findSum(TreeNode *root) {
    if (nullptr == root) {
      return 0;
    }
    return root->val + findSum(root->left) + findSum(root->right);
  }
};
