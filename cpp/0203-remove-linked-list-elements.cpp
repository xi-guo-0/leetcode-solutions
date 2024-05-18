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
  ListNode *removeElements(ListNode *head, int val) {
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *p = &dummy;
    while (p->next) {
      if (p->next->val == val) {
        ListNode *q = p->next;
        p->next = q->next;
        delete q;
      } else {
        p = p->next;
      }
    }
    return dummy.next;
  }
};
