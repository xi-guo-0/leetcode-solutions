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
  TreeNode *bstToGst(TreeNode *root) {
    stack<TreeNode *> s;
    TreeNode *p = root;
    int sum = 0;
    while (!s.empty() || p != nullptr) {
      if (p != nullptr) {
        s.push(p);
        p = p->right;
      } else {
        p = s.top();
        s.pop();
        p->val += sum;
        sum = p->val;
        p = p->left;
      }
    }
    return root;
  }
};
