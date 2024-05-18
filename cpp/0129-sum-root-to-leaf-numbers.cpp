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
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
    
    int sumNumbers(TreeNode* root, long long n) {
        if (root == nullptr)
            return 0;
        long long sum = n * 10 + root->val;    
        
        if (root->left == nullptr && root->right == nullptr)
            return sum;
        return sumNumbers(root->left, sum) +
               sumNumbers(root->right, sum);
    }
};
