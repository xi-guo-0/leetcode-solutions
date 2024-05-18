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
  bool isPalindrome(ListNode *head) {
    if (!head || !head->next) {
      return true;
    }
    const bool isOdd = lenOfList(head) % 2 == 1;
    ListNode leftDummy(-1);
    ListNode rightDummy(-1);
    rightDummy.next = head;
    ListNode *p = &rightDummy;
    ListNode *q = p;
    ListNode *r = &leftDummy;
    while (q->next && q->next->next) {
      q = q->next->next;
      ListNode *t = p->next;
      p->next = t->next;
      t->next = r->next;
      r->next = t;
    }
    p = leftDummy.next;
    q = rightDummy.next;
    if (isOdd)
      q = q->next;
    while (p && q && p->val == q->val) {
      p = p->next;
      q = q->next;
    }
    return !p && !q;
  }

private:
  int lenOfList(ListNode *p) {
    int result = 0;
    while (p) {
      p = p->next;
      result++;
    }
    return result;
  }
};
