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
  vector<int> flipMatchVoyage(TreeNode *root, const vector<int> &voyage) {
    idx = 0;
    if (dfs(root, voyage)) {
      return result;
    } else {
      return vector<int>{-1};
    }
  }

private:
  vector<int> result;
  int idx;

  bool dfs(TreeNode *node, const vector<int> &voyage) {
    if (!node)
      return true;
    if (node->val != voyage[idx++])
      return false;

    if (node->left && node->left->val != voyage[idx]) {
      result.push_back(node->val);
      return dfs(node->right, voyage) && dfs(node->left, voyage);
    } else {
      return dfs(node->left, voyage) && dfs(node->right, voyage);
    }
  }
};
