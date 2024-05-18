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
    ListNode* partition(ListNode* head, int x) {
        ListNode result(-1);
        ListNode dummy(-1);
        dummy.next = head;

        ListNode *last = &result;
        ListNode *prev = &dummy;
        ListNode *cur = prev->next;

        while (cur != nullptr) {
            if (cur->val < x) {
                prev->next = cur->next;
                cur->next = nullptr;
                last->next = cur;
                last = last->next;
                cur = prev->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        last->next = dummy.next;
        return result.next;
    }
};
