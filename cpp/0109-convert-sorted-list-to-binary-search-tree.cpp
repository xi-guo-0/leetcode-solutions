/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, listLength(head));
    }
    
    TreeNode* sortedListToBST(ListNode* head, int len) {
        if (len == 0) return nullptr;
        if (len == 1) return new TreeNode(head->val);
        
        TreeNode* root = new TreeNode(nth_node(head, len/2 + 1)->val);
        root->left = sortedListToBST(head, len/2);
        root->right = sortedListToBST(nth_node(head, len/2 + 2),
                                     (len - 1)/2);
        return root;
    }
    
    int listLength(ListNode* node) {
        int n = 0;
        
        while (node) {
            n++;
            node = node->next;
        }
        
        return n;
    }

    ListNode* nth_node(ListNode* node, int n) {
        while (--n)
            node = node->next;
        return node;
    }
};
