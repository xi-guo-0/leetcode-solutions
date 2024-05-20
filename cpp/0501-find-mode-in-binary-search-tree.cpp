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
  vector<int> findMode(TreeNode *root) {
    if (!root) {
      return vector<int>();
    }
    vector<pair<int, int>> count;
    TreeNode *cur = root, *prev = nullptr;

    auto visit = [&count, &prev, &cur]() {
      if (prev != nullptr && prev->val == cur->val) {
        count.back().second++;
      } else {
        count.push_back(make_pair(cur->val, 1));
      }
    };

    while (cur != nullptr) {
      if (cur->left == nullptr) {
        visit();
        prev = cur;
        cur = cur->right;
      } else {
        TreeNode *node = cur->left;
        while (node->right != nullptr && node->right != cur)
          node = node->right;

        if (node->right == nullptr) {
          node->right = cur;
          cur = cur->left;
        } else {
          visit();
          node->right = nullptr;
          prev = cur;
          cur = cur->right;
        }
      }
    }
    sort(count.begin(), count.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           return a.second != b.second ? a.second > b.second
                                       : a.first < b.first;
         });
    int mode = count.front().second;
    vector<int> result;
    for (auto it = count.begin(); it != count.end() && it->second == mode; it++)
      result.push_back(it->first);
    return result;
  }
};
