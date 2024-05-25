#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
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
  int findSecondMinimumValue(TreeNode *root) {
    if (root == nullptr) {
      return -1;
    }

    queue<TreeNode *> queue;
    set<int> set;
    queue.push(root);

    while (!queue.empty()) {
      TreeNode *node = queue.front();
      queue.pop();

      if (node->left != nullptr) {
        queue.push(node->left);
      }
      if (node->right != nullptr) {
        queue.push(node->right);
      }
      set.insert(node->val);
    }

    if (set.size() < 2) {
      return -1;
    }

    vector<int> nums(set.begin(), set.end());
    sort(nums.begin(), nums.end());

    return nums[1];
  }
};
