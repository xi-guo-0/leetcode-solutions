/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        Node* p = &dummy;
        Node* q = head;
        unordered_map<Node*, Node*> memo;
        while (q) {
            p->next = new Node(q->val);
            memo[q] = p->next;
            p = p->next;
            q = q->next;
        }
        
        p = dummy.next;
        q = head;
        while (q) {
            if (q->random) {
                p->random = memo[q->random];
            }
            p = p->next;
            q = q->next;
        }
        return dummy.next;
    }

};
