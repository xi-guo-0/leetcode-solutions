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
  bool isCousins(TreeNode *root, int x, int y) {
    TreeNode *parent1 = nullptr, *parent2 = nullptr;
    int deep1 = 0, deep2 = 0;
    stack<tuple<TreeNode *, TreeNode *, int>> s;
    s.push(make_tuple(root, nullptr, 0));

    while (!s.empty()) {
      TreeNode *n = get<0>(s.top());
      TreeNode *p = get<1>(s.top());
      int d = get<2>(s.top());
      s.pop();
      if (x == n->val) {
        parent1 = p;
        deep1 = d;
      }
      if (n->right != nullptr) {
        s.push(make_tuple(n->right, n, d + 1));
      }
      if (n->left != nullptr) {
        s.push(make_tuple(n->left, n, d + 1));
      }
    }

    while (!s.empty())
      s.pop();

    s.push(make_tuple(root, nullptr, 0));

    while (!s.empty()) {
      TreeNode *n = get<0>(s.top());
      TreeNode *p = get<1>(s.top());
      int d = get<2>(s.top());
      s.pop();
      if (y == n->val) {
        parent2 = p;
        deep2 = d;
      }
      if (n->right != nullptr) {
        s.push(make_tuple(n->right, n, d + 1));
      }
      if (n->left != nullptr) {
        s.push(make_tuple(n->left, n, d + 1));
      }
    }
    return deep1 == deep2 && parent1 && parent2 && parent1->val != parent2->val;
  }
};
