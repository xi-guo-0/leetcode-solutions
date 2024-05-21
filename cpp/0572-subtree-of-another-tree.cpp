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
  bool isSubtree(TreeNode *s, TreeNode *t) {
    if (!s) {
      return false;
    }
    return equals(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
  }

private:
  bool equals(const TreeNode *s, const TreeNode *t) {
    if (!s && !t) {
      return true;
    } else if (!s || !t) {
      return false;
    }
    return s->val == t->val && equals(s->left, t->left) &&
           equals(s->right, t->right);
  }
};
