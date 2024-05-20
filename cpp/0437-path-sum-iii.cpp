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
  int pathSum(TreeNode *root, int sum) {
    if (root == nullptr) {
      return 0;
    }
    return pathSumFromRoot(root, sum) + pathSum(root->left, sum) +
           pathSum(root->right, sum);
  }

private:
  int pathSumFromRoot(TreeNode *root, int sum) {
    if (root == nullptr) {
      return 0;
    }
    int result = root->val == sum;
    result += pathSumFromRoot(root->left, sum - root->val);
    result += pathSumFromRoot(root->right, sum - root->val);
    return result;
  }
};
