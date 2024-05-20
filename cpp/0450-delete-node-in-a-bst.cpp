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
  TreeNode *deleteNode(TreeNode *root, const int key) {
    TreeNode **p = searchNode(&root, key);
    if (p == nullptr)
      return root;
    if ((*p)->left == nullptr && (*p)->right == nullptr) {
      (*p) = nullptr;
      return root;
    }
    if ((*p)->right == nullptr) {
      (*p) = (*p)->left;
      return root;
    }
    TreeNode **next = &(*p)->right;
    while ((*next) != nullptr && (*next)->left != nullptr) {
      next = &(*next)->left;
    }
    (*p)->val = (*next)->val;
    *next = deleteNode((*next), (*next)->val);
    return root;
  }

private:
  TreeNode **searchNode(TreeNode **root, const int key) {
    if ((*root) == nullptr)
      return nullptr;
    if ((*root)->val == key)
      return root;
    if ((*root)->val < key)
      return searchNode(&(*root)->right, key);
    return searchNode(&(*root)->left, key);
  }
};
