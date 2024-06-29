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
  string smallestFromLeaf(TreeNode *root) {
    if (!root) {
      return "";
    }
    dfs(root, "");
    return result;
  }

private:
  string result = "~";

  void dfs(TreeNode *root, string s) {
    s += static_cast<char>(root->val + 'a');
    if (!root->left && !root->right) {
      reverse(s.begin(), s.end());
      if (s < result)
        result = s;
    }
    if (root->left)
      dfs(root->left, s);
    if (root->right)
      dfs(root->right, s);
  }
};
