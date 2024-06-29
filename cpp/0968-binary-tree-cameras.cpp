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
  enum State { NOT_MONITORED, MONITORED_NO_CAMERA, MONITORED_WITH_CAMERA };

  int minCameraCover(TreeNode *root) {
    int cameras = 0;

    auto dfs = [&](auto &&self, TreeNode *node) -> State {
      if (!node)
        return MONITORED_NO_CAMERA;

      State left = self(self, node->left);
      State right = self(self, node->right);

      if (left == NOT_MONITORED || right == NOT_MONITORED) {
        cameras++;
        return MONITORED_WITH_CAMERA;
      }

      if (left == MONITORED_WITH_CAMERA || right == MONITORED_WITH_CAMERA) {
        return MONITORED_NO_CAMERA;
      }

      return NOT_MONITORED;
    };

    if (dfs(dfs, root) == NOT_MONITORED) {
      cameras++;
    }

    return cameras;
  }
};
