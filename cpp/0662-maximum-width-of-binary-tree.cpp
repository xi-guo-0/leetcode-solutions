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
  int widthOfBinaryTree(TreeNode *root) {
    long long unsigned ans = 0;
    queue<pair<TreeNode *, long long unsigned>> q;
    if (root) {
      q.emplace(root, 1);
    }
    while (!q.empty()) {
      int n = q.size();
      long long unsigned const l = q.front().second;
      long long unsigned r = q.front().second;
      while (n--) {
        TreeNode *node = q.front().first;
        long long unsigned const index = q.front().second;
        r = index;
        q.pop();

        if (node->left) {
          q.emplace(node->left, 2 * index);
        }
        if (node->right) {
          q.emplace(node->right, 2 * index + 1);
        }
      }
      ans = max(ans, r - l + 1);
    }
    return static_cast<int>(ans);
  }
};
