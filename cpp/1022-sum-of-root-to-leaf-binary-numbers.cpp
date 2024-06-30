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
  int sumRootToLeaf(TreeNode *root) {
    long long sum = 0;
    stack<pair<const TreeNode *, long long>> s;
    if (root != nullptr)
      s.push(make_pair(root, 0));
    while (!s.empty()) {
      const TreeNode *p = s.top().first;
      long long val = s.top().second;
      s.pop();
      if (p->left == nullptr && p->right == nullptr) {
        sum = (sum + (val << 1) + p->val) % 1000000007;
      }
      if (p->right != nullptr)
        s.push(make_pair(p->right, ((val << 1) + p->val) % 1000000007));
      if (p->left != nullptr)
        s.push(make_pair(p->left, ((val << 1) + p->val) % 1000000007));
    }
    return sum;
  }
};
