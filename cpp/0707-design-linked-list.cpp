struct Node {
  int val;
  Node *next;
  Node(int val = -1, Node *next = nullptr) : val(val), next(next) {}
};

class MyLinkedList {
private:
  Node *head;
  int sz;
  Node *before_ptr(int index) {
    if (index <= 0)
      return head;
    else if (sz < index)
      return nullptr;
    Node *p = head;
    while (index--)
      p = p->next;
    return p;
  }

public:
  MyLinkedList() {
    head = new Node();
    sz = 0;
  }

  int get(int index) {
    if (0 <= index && index < sz) {
      Node *p = before_ptr(index);
      return p->next->val;
    }
    return -1;
  }

  void addAtHead(int val) { addAtIndex(0, val); }

  void addAtTail(int val) { addAtIndex(sz, val); }

  void addAtIndex(int index, int val) {
    if (index <= sz) {
      Node *p = before_ptr(index);
      Node *q = new Node(val, p->next);
      p->next = q;
      sz++;
    }
  }

  void deleteAtIndex(int index) {
    if (0 <= index && index < sz) {
      Node *p = before_ptr(index);
      Node *q = p->next;
      p->next = q->next;
      delete q;
      sz--;
    }
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
