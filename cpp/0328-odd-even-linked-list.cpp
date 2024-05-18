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
  ListNode *oddEvenList(ListNode *head) {
    ListNode dummy(-1);
    ListNode even(-1);
    dummy.next = head;
    bool isEven = false;
    ListNode *p = &dummy;
    ListNode *q = &even;
    while (p->next) {
      if (isEven) {
        ListNode *r = p->next;
        p->next = r->next;
        r->next = q->next;
        q->next = r;
        q = q->next;
      } else {
        p = p->next;
      }
      isEven = !isEven;
    }
    p->next = even.next;
    return dummy.next;
  }
};
