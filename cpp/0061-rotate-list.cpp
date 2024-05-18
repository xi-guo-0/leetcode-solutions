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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) { return head; }
        ListNode dummy(-1);
        dummy.next = head;
        int len = 0;
        ListNode *last = &dummy;
        for (; last->next; last = last->next)
            len++;
        k %= len;
        k = len - k;
        ListNode *cut = &dummy;
        while (k--) {
            cut = cut->next;
        }
        last->next = dummy.next;
        dummy.next = cut->next;
        cut->next = nullptr;
        return dummy.next;
    }
};
