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
  int findBottomLeftValue(TreeNode *root) {
    return findBottomLeftValue(make_pair(root, 0)).first->val;
  }

private:
  pair<TreeNode *, int> findBottomLeftValue(pair<TreeNode *, int> p) {
    if (!p.first || (!p.first->left && !p.first->right)) {
      return p;
    } else if (!p.first->left) {
      return findBottomLeftValue(make_pair(p.first->right, p.second + 1));
    } else if (!p.first->right) {
      return findBottomLeftValue(make_pair(p.first->left, p.second + 1));
    }
    pair<TreeNode *, int> l =
        findBottomLeftValue(make_pair(p.first->left, p.second + 1));
    pair<TreeNode *, int> r =
        findBottomLeftValue(make_pair(p.first->right, p.second + 1));
    if (l.second >= r.second)
      return l;
    return r;
  }
};
