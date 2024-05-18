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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            auto p = s.top();
            s.pop();
            
            if (p->right)
                s.push(p->right);
            if (p->left)
                s.push(p->left);
            
            p->left = nullptr;
            if (!s.empty())
                p->right = s.top();
        }
    }
};
