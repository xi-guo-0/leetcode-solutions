/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
  Node *flatten(Node *head) {
    if (!head)
      return nullptr;
    Node *pre = nullptr;
    Node *cur = nullptr;
    stack<Node *> sk;
    sk.push(head);
    while (!sk.empty()) {
      cur = sk.top();
      sk.pop();
      if (cur->next) {
        sk.push(cur->next);
      }
      if (cur->child) {
        sk.push(cur->child);
        cur->child = nullptr;
      }
      if (pre) {
        pre->next = cur;
        cur->prev = pre;
      }
      pre = cur;
    }
    return head;
  }
};
