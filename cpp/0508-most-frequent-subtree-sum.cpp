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
  vector<int> findFrequentTreeSum(TreeNode *root) {
    vector<int> result;
    if (!root) {
      return result;
    }
    postSum(root);
    auto it = sum.begin();
    for (auto jt = sum.begin(); jt != sum.end(); jt++)
      if (it->second < jt->second)
        it = jt;
    for (auto jt = sum.begin(); jt != sum.end(); jt++)
      if (it->second == jt->second)
        result.push_back(jt->first);
    return result;
  }

private:
  map<int, int> sum;

  int postSum(TreeNode *root) {
    const int L = root->left ? postSum(root->left) : 0;
    const int R = root->right ? postSum(root->right) : 0;
    const int now = L + R + root->val;
    if (sum.count(now))
      sum[now]++;
    else
      sum[now] = 1;
    return now;
  }
};
