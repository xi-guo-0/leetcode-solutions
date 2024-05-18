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
  vector<int> rightSideView(TreeNode *root) {
    vector<int> result;
    queue<TreeNode *> current, next;
    if (root)
      current.push(root);

    while (!current.empty()) {
      int val = current.front()->val;
      while (!current.empty()) {
        root = current.front();
        current.pop();
        val = root->val;
        if (root->left)
          next.push(root->left);
        if (root->right)
          next.push(root->right);
      }
      result.push_back(val);
      swap(current, next);
    }
    return result;
  }
};
