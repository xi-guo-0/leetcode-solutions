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
  bool findTarget(TreeNode *root, int k) {
    if (nullptr == root) {
      return false;
    }
    std::unordered_set<int> set;
    return searchTarget(root, k, set);
  }

private:
  bool searchTarget(TreeNode *root, int k, std::unordered_set<int> &set) {
    if (nullptr == root) {
      return false;
    }
    if (set.find(k - root->val) != set.end()) {
      return true;
    }
    set.insert(root->val);
    return searchTarget(root->left, k, set) ||
           searchTarget(root->right, k, set);
  }
};
