#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
    convertToFullTree(root, 1);
    vector<int> result;
    for (const auto &m : ft)
      if (fullTreeDistance(ft[m.first], ft[target]) == K)
        result.push_back(m.first->val);
    return result;
  }

private:
  map<TreeNode *, int> ft;

  void convertToFullTree(TreeNode *root, int n) {
    if (root != nullptr) {
      ft[root] = n;
      if (root->left)
        convertToFullTree(root->left, (n << 1));
      if (root->right)
        convertToFullTree(root->right, (n << 1) + 1);
    }
  }

  int fullTreeDistance(int x, int y) {
    int dis = 0;
    while (x != y) {
      if (x < y) {
        y = y >> 1;
      } else {
        x = x >> 1;
      }
      dis++;
    }
    return dis;
  }
};
