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
  TreeNode *recoverFromPreorder(string traversal) {
    auto v = readStr(traversal);
    if (v.empty()) {
      return nullptr;
    }
    auto root = new TreeNode(v.front().first);
    stack<pair<TreeNode *, int>> s;
    s.push(make_pair(root, 0));
    for (int i = 1; i < v.size(); i++) {
      auto cur = new TreeNode(v[i].first);
      while (s.top().second >= v[i].second) {
        s.pop();
      }
      if (s.top().first->left)
        s.top().first->right = cur;
      else
        s.top().first->left = cur;
      s.push(make_pair(cur, v[i].second));
    }
    return root;
  }

private:
  vector<pair<int, int>> readStr(const string &s) {
    vector<pair<int, int>> v;
    const int n = s.size();
    int i = 0, j = 0, val = 0, dep = 0;
    while (j < n) {
      i = j;
      while (j < n && s[j] == '-')
        j++;
      dep = j - i;
      i = j;
      while (j < n && s[j] != '-')
        j++;
      val = stoi(s.substr(i, j - i));
      v.push_back(make_pair(val, dep));
    }
    return v;
  }
};
