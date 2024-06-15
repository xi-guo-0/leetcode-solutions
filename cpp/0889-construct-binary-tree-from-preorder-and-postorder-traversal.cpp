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
  TreeNode *constructFromPrePost(const vector<int> &pre,
                                 const vector<int> &post) {
    return constructFromPrePost(pre.begin(), pre.end(), post.begin(),
                                post.end());
  }

private:
  template <typename ForwardIt>
  TreeNode *constructFromPrePost(ForwardIt pre_first, ForwardIt pre_last,
                                 ForwardIt post_first, ForwardIt post_last) {
    if (pre_first == pre_last) {
      return nullptr;
    } else if (next(pre_first) == pre_last) {
      return new TreeNode(*pre_first);
    }
    TreeNode *root = new TreeNode(*pre_first);
    auto pre = next(pre_first);
    auto post = post_first;
    set<int> a;
    set<int> b;
    do {
      a.insert(*pre);
      b.insert(*post);
      pre++;
      post++;
    } while (a != b);
    root->left = constructFromPrePost(next(pre_first), pre, post_first, post);
    root->right = constructFromPrePost(pre, pre_last, post, post_last);
    return root;
  }
};
