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
  bool isCompleteTree(TreeNode *root) {
    if (!root) {
      return true;
    }
    queue<pair<TreeNode *, int>> current, next;
    set<int> ft;
    current.push(make_pair(root, 1));

    while (!current.empty()) {
      while (!current.empty()) {
        root = current.front().first;
        int n = current.front().second;
        current.pop();
        if (n >= 128) {
          return false;
        }
        ft.insert(n);
        if (root->left)
          next.push(make_pair(root->left, (n << 1)));
        if (root->right)
          next.push(make_pair(root->right, (n << 1) + 1));
      }
      swap(current, next);
    }
    for (int i = 1; i <= ft.size(); i++)
      if (!ft.count(i))
        return false;
    return true;
  }
};
