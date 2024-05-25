class MyHashSet {
public:
  MyHashSet() { arr = vector<Node *>(n, new Node(-1)); }

  void add(int key) {
    const int hash = hasher(key);
    if (!contains(key)) {
      Node *h = arr[hash];
      Node *node = new Node(key);
      node->next = h->next;
      h->next = node;
    }
  }

  void remove(int key) {
    const int hash = hasher(key);
    for (Node *h = arr[hash]; h->next; h = h->next)
      if (h->next->key == key) {
        Node *p = h->next;
        h->next = p->next;
        delete p;
        return;
      }
  }

  bool contains(int key) {
    const int hash = hasher(key);
    for (Node *h = arr[hash]->next; h; h = h->next)
      if (h->key == key)
        return true;
    return false;
  }

private:
  struct Node {
    int key;
    Node *next;
    Node(int k) : key(k), next(nullptr) {}
  };

  static const int n = 2017;
  vector<Node *> arr;
  static inline int hasher(long long key) { return (key * key) % n; }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
