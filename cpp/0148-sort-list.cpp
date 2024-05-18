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
    ListNode* sortList(ListNode* head) {
        vector<ListNode*> v;
        for (auto p = head; p; p = p->next)
            v.push_back(p);
        sort(v.begin(), v.end(), [](ListNode* a, ListNode* b){
           return a->val < b->val; 
        });
        ListNode dummy(INT_MIN);
        ListNode* p = &dummy;
        for (auto i : v) {
            p->next = i;
            p = p->next;
        }
        p->next = nullptr;
        return dummy.next;
    }
};
