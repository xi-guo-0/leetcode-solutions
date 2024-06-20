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
class CBTInserter {
public:
  CBTInserter(TreeNode *root) {
    t.push_back(nullptr);
    queue<TreeNode *> q;
    if (root != nullptr)
      q.push(root);
    while (!q.empty()) {
      root = q.front();
      q.pop();
      t.push_back(root);
      if (root->left)
        q.push(root->left);
      if (root->right)
        q.push(root->right);
    }
  }

  int insert(int v) {
    int i = t.size();
    t.push_back(new TreeNode(v));
    if (i % 2 == 0)
      t[i / 2]->left = t[i];
    else
      t[i / 2]->right = t[i];
    return t[i / 2]->val;
  }

  TreeNode *get_root() { return t[1]; }

private:
  vector<TreeNode *> t;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
