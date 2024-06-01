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

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  int minDiffInBST(TreeNode *root) {
    if (nullptr == root) {
      return 0;
    }
    std::vector<int> list;
    convert(root, list);
    int result = std::numeric_limits<int>::max();
    for (size_t i = 1; i < list.size(); i++) {
      if (result > list[i] - list[i - 1]) {
        result = list[i] - list[i - 1];
      }
    }
    return result;
  }

private:
  void convert(TreeNode *root, std::vector<int> &list) {
    if (nullptr != root->left) {
      convert(root->left, list);
    }
    list.push_back(root->val);
    if (nullptr != root->right) {
      convert(root->right, list);
    }
  }
};
