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
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    if (nums.size() == 0) {
      return nullptr;
    } else if (nums.size() == 1) {
      return new TreeNode(nums.front());
    }
    return constructMaximumBinaryTree(nums.begin(), nums.end());
  }

private:
  template <typename ForwardIt>
  TreeNode *constructMaximumBinaryTree(ForwardIt first, ForwardIt last) {
    auto it = max_element(first, last);
    TreeNode *root = new TreeNode(*it);
    if (first != it)
      root->left = constructMaximumBinaryTree(first, it);
    if (next(it) != last)
      root->right = constructMaximumBinaryTree(next(it), last);
    return root;
  }
};
