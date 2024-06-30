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
  TreeNode *bstFromPreorder(vector<int> &preorder) {
    return bstFromPreorder(preorder.begin(), preorder.end());
  }

private:
  template <typename ForwardIt>
  TreeNode *bstFromPreorder(ForwardIt first, ForwardIt last) {
    if (first == last) {
      return nullptr;
    } else if (next(first) == last) {
      return new TreeNode(*first);
    }
    TreeNode *root = new TreeNode(*first);
    auto it = find_if(next(first), last, [&first](const decltype(*first) &a) {
      return *first < a;
    });
    root->left = bstFromPreorder(next(first), it);
    root->right = bstFromPreorder(it, last);
    return root;
  }
};
