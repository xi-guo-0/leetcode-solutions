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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> current, next;
        bool zigzag = false;
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
            if (zigzag) {
                std::reverse(level.begin(), level.end());
            }
            zigzag = !zigzag;
            result.push_back(level);
            swap(next, current);
        }
        return result;        
    }
};
