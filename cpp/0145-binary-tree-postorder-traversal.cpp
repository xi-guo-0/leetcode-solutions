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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode dummy(-1);
        TreeNode *cur, *prev = nullptr;
        std::function<void(const TreeNode*)> visit = [&result](const TreeNode *node) {
            result.push_back(node->val);
        };
        
        dummy.left = root;
        cur = &dummy;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                prev = cur;
                cur = cur->right;
            } else {
                TreeNode *node = cur->left;
                while (node->right != nullptr && node->right != cur)
                    node = node->right;
                
                if (node->right == nullptr) {
                    node->right = cur;
                    prev = cur;
                    cur = cur->left;
                } else {
                    visit_reverse(cur->left, prev, visit);
                    prev->right = nullptr;
                    prev = cur;
                    cur = cur->right;
                }
            }
        }        
        return result;
    }
    
private:
    static void reverse(TreeNode *from, TreeNode *to) {
        TreeNode *x = from, *y = from->right, *z;
        if (from == to) return;
        
        while (x != to) {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
        }
    }
    
    static void visit_reverse(TreeNode* from, TreeNode *to, std::function<void(const TreeNode*)>& visit) {
        TreeNode *p = to;
        reverse(from, to);
        
        while (true) {
            visit(p);
            if (p == from)
                break;
            p = p->right;
        }
        reverse(to, from);
    }
};
