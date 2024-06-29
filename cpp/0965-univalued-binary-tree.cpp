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
  bool isUnivalTree(TreeNode *root) {
    if (!root) {
      return true;
    }
    int val = root->val;
    stack<const TreeNode *> s;
    s.push(root);
    while (!s.empty()) {
      const TreeNode *p = s.top();
      s.pop();
      if (val != p->val) {
        return false;
      }

      if (p->right != nullptr)
        s.push(p->right);
      if (p->left != nullptr)
        s.push(p->left);
    }
    return true;
  }
};
