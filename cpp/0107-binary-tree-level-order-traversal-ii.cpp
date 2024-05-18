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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        stack<vector<int>> inverse_result;
        queue<TreeNode*> current, next;
        if (root == nullptr)
            return result;
        else
            current.push(root);
        
        while (!current.empty()) {
            vector<int> level;
            while (!current.empty()) {
                TreeNode* node = current.front();
                current.pop();
                level.push_back(node->val);
                if (node->left != nullptr) next.push(node->left);
                if (node->right != nullptr) next.push(node->right);
            }
            inverse_result.push(level);
            swap(next, current);
        }
        while (!inverse_result.empty()) {
            result.push_back(inverse_result.top());
            inverse_result.pop();
        }
        return result;
    }
};
