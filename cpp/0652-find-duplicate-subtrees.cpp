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
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    serialize(root);
    vector<TreeNode *> res;
    for (const auto &item : dict)
      if (item.second.count > 1)
        res.push_back(item.second.root);
    return res;
  }

private:
  struct SubTreeCount {
    TreeNode *root;
    int count;
  };

  unordered_map<size_t, SubTreeCount> dict;
  hash<string> hasher;

  size_t serialize(TreeNode *root) {
    if (root == nullptr) {
      return hasher("[]");
    }
    char buf[2048];
    snprintf(buf, 2048, "[%d %d %d]", root->val, serialize(root->left),
             serialize(root->right));
    size_t res = hasher(buf);
    if (dict.count(res) == 0)
      dict.insert(pair<size_t, SubTreeCount>(res, {root, 1}));
    else
      dict[res].count++;
    return res;
  }
};
