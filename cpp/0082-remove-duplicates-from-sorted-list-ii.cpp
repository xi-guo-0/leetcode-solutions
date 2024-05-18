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
        if (!head || !head->next) { return head; }
        ListNode dummy(-1);
        dummy.next = head;
        
        for (auto p = &dummy; p->next; ) {
            auto q = p->next;
            if (q->next && q->val == q->next->val) {
                for (auto r = q->next; r && q->val == r->val; ) {
                    q->next = r->next;
                    delete r;
                    r = q->next;
                }
                p->next = q->next;
                delete q;
                q = p->next;
            } else {
                p = p->next;
            }
        }
        return dummy.next;
    }
};
