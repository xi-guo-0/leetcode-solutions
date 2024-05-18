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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) { return head; }
        ListNode dummy(-1);
        dummy.next = head;
        for (auto p = dummy.next; p->next != nullptr; ) {
            if (p->val == p->next->val) {
                auto q = p->next;
                p->next = q->next;
                delete q;
            } else {
                p = p->next;
            }
        }
        return dummy.next;
    }
};
