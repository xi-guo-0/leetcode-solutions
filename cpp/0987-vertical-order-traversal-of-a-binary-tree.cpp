#include <algorithm>
#include <iostream>
#include <map>
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
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    vector<pair<int, pair<int, int>>> nodes;
    dfs(nodes, root, 0, 0);

    sort(nodes.begin(), nodes.end(), [](const auto &a, const auto &b) {
      return a.first < b.first ||
             (a.first == b.first && (a.second.first < b.second.first ||
                                     (a.second.first == b.second.first &&
                                      a.second.second < b.second.second)));
    });

    map<int, vector<int>> cols;
    for (const auto &node : nodes) {
      cols[node.first].push_back(node.second.second);
    }

    vector<vector<int>> result;
    for (const auto &col : cols) {
      result.push_back(col.second);
    }

    return result;
  }

private:
  void dfs(vector<pair<int, pair<int, int>>> &nodes, TreeNode *root, int r,
           int c) {
    if (root) {
      nodes.push_back({c, {r, root->val}});
      dfs(nodes, root->left, r + 1, c - 1);
      dfs(nodes, root->right, r + 1, c + 1);
    }
  }
};
