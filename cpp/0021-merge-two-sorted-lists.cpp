/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* p = &dummy;
        ListNode* q = list1;
        ListNode* r = list2;
        while (q && r) {
            if (q->val <= r->val) {
                p->next = q;
                q = q->next;
            } else {
                p->next = r;
                r = r->next;
            }
            p = p->next;
        }
        if (q) {
            p->next = q;
        } else {
            p->next = r;
        }
        return dummy.next;
    }
};
