/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k < 2)
            return head;
        ListNode *next_group = head;
        for (int i = 0; i < k; i++) {
            if (next_group)
                next_group = next_group->next;
            else
                return head;
        }
        
        ListNode *new_next_group = reverseKGroup(next_group, k);
        ListNode *prev = nullptr,
                 *cur = head;
        while (cur != next_group) {
            auto next = cur->next;
            cur->next = prev ? prev : new_next_group;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
