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
  vector<vector<string>> printTree(TreeNode *root) {
    if (!root) {
      return vector<vector<string>>();
    }
    const int m = depth(root);
    const int n = (1 << m) - 1;
    vector<vector<string>> result(m, vector<string>(n, string("")));
    queue<tuple<TreeNode *, int, int>> q;
    q.push(make_tuple(root, 0, n / 2));
    while (!q.empty()) {
      root = get<0>(q.front());
      const int r = get<1>(q.front());
      const int c = get<2>(q.front());
      q.pop();
      result[r][c] = to_string(root->val);
      const int step = r + 1 < m ? 1 << (m - r - 2) : 0;
      if (root->left)
        q.push(make_tuple(root->left, r + 1, c - step));
      if (root->right)
        q.push(make_tuple(root->right, r + 1, c + step));
    }
    return result;
  }

private:
  int depth(TreeNode *root) {
    const int L = root->left ? depth(root->left) : 0;
    const int R = root->right ? depth(root->right) : 0;
    return 1 + max(L, R);
  }
};
