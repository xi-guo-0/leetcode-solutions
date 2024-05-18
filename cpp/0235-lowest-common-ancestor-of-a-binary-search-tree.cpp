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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!p) {
      return q;
    }
    if (!q) {
      return p;
    }
    if (!root) {
      return root;
    }
    vector<TreeNode *> v1;
    vector<TreeNode *> v2;
    for (auto r = root; r && r->val != p->val;) {
      v1.push_back(r);
      if (r->val < p->val)
        r = r->right;
      else {
        r = r->left;
      }
    }
    v1.push_back(p);
    for (auto r = root; r && r->val != q->val;) {
      v2.push_back(r);
      if (r->val < q->val)
        r = r->right;
      else {
        r = r->left;
      }
    }
    v2.push_back(q);
    int n = min(v1.size(), v2.size());
    int i = 0;
    for (; i < n && v1[i] == v2[i];)
      i++;
    return v1[i - 1];
  }
};
