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
    ListNode* insertionSortList(ListNode* head) {
        vector<ListNode*> vec;
        for (auto p = head; p; p = p->next) {
            vec.push_back(p);
        }
        sort(vec.begin(), vec.end(), [](ListNode* a, ListNode* b){
            return a->val < b->val;
        });
        ListNode dummy(INT_MIN);
        ListNode* p = &dummy;
        for (auto q : vec) {
            p->next = q;
            p = p->next;
        }
        p->next = nullptr;
        return dummy.next;
    }
};
