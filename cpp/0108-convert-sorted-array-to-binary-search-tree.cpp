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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums.begin(), nums.end());
    }
    
    template<typename IT>
    TreeNode* sortedArrayToBST(IT bit, IT eit) {
        auto length = distance(bit, eit);
        
        if (length <= 0)
            return nullptr;
        
        auto mit =  bit + length / 2;
        TreeNode* root = new TreeNode(*mit);
        root->left = sortedArrayToBST(bit, mit);
        root->right = sortedArrayToBST(mit + 1, eit);
        
        return root;
    }
};
