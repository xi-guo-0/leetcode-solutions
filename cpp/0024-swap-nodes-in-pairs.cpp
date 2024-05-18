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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        for (auto p = &dummy; p->next && p->next->next; p = p->next->next) {
            auto q = p->next;
            auto r = q->next;
            auto s = r->next;
            p->next = r;
            r->next = q;
            q->next = s;
        }
        return dummy.next;
    }
};
