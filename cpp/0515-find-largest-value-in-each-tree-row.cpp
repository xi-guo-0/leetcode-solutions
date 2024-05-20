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
  vector<int> largestValues(TreeNode *root) {
    vector<int> result;
    if (!root) {
      return result;
    }
    queue<TreeNode *> current, next;

    current.push(root);
    while (!current.empty()) {
      int line = INT_MIN;
      while (!current.empty()) {
        root = current.front();
        current.pop();
        line = max(line, root->val);
        if (root->left) {
          next.push(root->left);
        }
        if (root->right) {
          next.push(root->right);
        }
      }
      result.push_back(line);
      swap(current, next);
    }
    return result;
  }
};
