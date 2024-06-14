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
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> leaf1;
    vector<int> leaf2;
    stack<const TreeNode *> s;

    if (root1 != nullptr)
      s.push(root1);
    while (!s.empty()) {
      const TreeNode *p = s.top();
      s.pop();
      if (p->left == nullptr && p->right == nullptr)
        leaf1.push_back(p->val);
      if (p->right != nullptr)
        s.push(p->right);
      if (p->left != nullptr)
        s.push(p->left);
    }

    if (root2 != nullptr)
      s.push(root2);
    while (!s.empty()) {
      const TreeNode *p = s.top();
      s.pop();
      if (p->left == nullptr && p->right == nullptr)
        leaf2.push_back(p->val);
      if (p->right != nullptr)
        s.push(p->right);
      if (p->left != nullptr)
        s.push(p->left);
    }

    if (leaf1.size() != leaf2.size())
      return false;
    for (int i = 0; i < leaf1.size(); i++)
      if (leaf1[i] != leaf2[i])
        return false;

    return true;
  }
};

int main() { return 0; }
