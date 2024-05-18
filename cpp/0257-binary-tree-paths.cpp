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
  vector<string> binaryTreePaths(TreeNode *root) {
    if (!root) {
      return vector<string>();
    }
    if (!root->left && !root->right) {
      return vector<string>{to_string(root->val)};
    }
    const string arrow("->");
    vector<string> result;
    stack<pair<TreeNode *, string>> s;
    s.push(make_pair(root, to_string(root->val)));

    while (!s.empty()) {
      TreeNode *n = s.top().first;
      string p = s.top().second;
      s.pop();

      if (!n->left && !n->right) {
        result.push_back(p);
      }

      if (n->right) {
        s.push(make_pair(n->right, p + arrow + to_string(n->right->val)));
      }
      if (n->left) {
        s.push(make_pair(n->left, p + arrow + to_string(n->left->val)));
      }
    }

    return result;
  }
};
