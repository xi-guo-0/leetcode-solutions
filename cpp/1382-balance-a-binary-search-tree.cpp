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
  TreeNode *balanceBST(TreeNode *root) {
    std::vector<int> v;
    inorder(root, &v);
    return vectorToAVL(v, 0, v.size() - 1);
  }

private:
  void inorder(TreeNode *root, std::vector<int> *v) {
    if (root) {
      inorder(root->left, v);
      v->push_back(root->val);
      inorder(root->right, v);
    }
  }

  TreeNode *vectorToAVL(const std::vector<int> &v, int b, int e) {
    if (e < b) {
      return nullptr;
    } else {
      int mid = (b + e) / 2;
      return new TreeNode(v[mid], vectorToAVL(v, b, mid - 1),
                          vectorToAVL(v, mid + 1, e));
    }
  }
};
