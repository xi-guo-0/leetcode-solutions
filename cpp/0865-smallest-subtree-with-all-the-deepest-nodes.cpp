#include <utility>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

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
  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    return lcaDeepestLeaves(root).first;
  }

private:
  pair<TreeNode *, int> lcaDeepestLeaves(TreeNode *root, int depth = 0) {
    if (!root)
      return {nullptr, depth};
    auto [leftNode, leftDepth] = lcaDeepestLeaves(root->left, depth + 1);
    auto [rightNode, rightDepth] = lcaDeepestLeaves(root->right, depth + 1);
    if (leftDepth == rightDepth)
      return {root, leftDepth};
    return (leftDepth > rightDepth) ? make_pair(leftNode, leftDepth)
                                    : make_pair(rightNode, rightDepth);
  }
};

int main() { return 0; }
