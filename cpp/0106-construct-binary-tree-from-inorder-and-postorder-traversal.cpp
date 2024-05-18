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
    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {        
        return buildTree(rbegin(inorder),
                         rend(inorder),
                         rbegin(postorder),
                         rend(postorder));
    }
    
    template<typename RIt>
    TreeNode* buildTree(RIt in_rfirst,
                        RIt in_rlast,
                        RIt post_rfirst,
                        RIt post_rlast) {
        if (in_rfirst == in_rlast) return nullptr;
        if (post_rfirst == post_rlast) return nullptr;
        
        auto root = new TreeNode(*post_rfirst);
        
        auto inRootRPos = find(in_rfirst, in_rlast, *post_rfirst);
        auto RightSize = distance(in_rfirst, inRootRPos);
        
        root->right = buildTree(in_rfirst,
                                next(in_rfirst, RightSize),
                                next(post_rfirst),
                                next(post_rfirst, RightSize + 1));
        root->left = buildTree(next(inRootRPos),
                               in_rlast,
                               next(post_rfirst, RightSize + 1),
                               post_rlast);
        return root;
    }
};
