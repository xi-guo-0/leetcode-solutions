#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

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
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> result;
    if (!root)
      return result;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      double levelSum = 0;
      int levelCount = q.size();
      for (int i = 0; i < levelCount; ++i) {
        TreeNode *node = q.front();
        q.pop();
        levelSum += node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      result.push_back(levelSum / levelCount);
    }

    return result;
  }
};
