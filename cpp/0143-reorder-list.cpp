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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) { return ; }
        ListNode dummy(-1);
        dummy.next = head;

        auto mid = &dummy;
        for (auto p = mid; p && p->next; p = p->next->next)
            mid = mid->next;
        
        auto right = reverse(mid->next);
        mid->next = nullptr;
        
        auto cur = head;
        while (cur->next) {
            auto tmp = cur->next;
            cur->next = right;
            right = right->next;
            cur->next->next = tmp;
            cur = tmp;
        }
        cur->next = right;
    }
    
    ListNode* reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode dummy(-1);
        for (auto p = head; p; ) {
            auto q = p;
            p = q->next;
            q->next = dummy.next;
            dummy.next = q;
        }
        return dummy.next;
    }
};
