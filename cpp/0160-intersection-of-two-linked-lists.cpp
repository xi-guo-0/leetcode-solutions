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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int la = getLength(headA);
    int lb = getLength(headB);
    if (la < lb) {
      swap(la, lb);
      swap(headA, headB);
    }
    for (int i = la - lb; 0 < i; --i) {
      headA = headA->next;
    }
    while (headA != headB) {
      headA = headA->next;
      headB = headB->next;
    }
    return headA;
  }

private:
  int getLength(ListNode *head) {
    ListNode dummy;
    dummy.next = head;
    ListNode *p = &dummy;
    int ans = 0;
    while (p->next) {
      p = p->next;
      ++ans;
    }
    return ans;
  }
};
