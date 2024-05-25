class MyHashMap {
public:
  MyHashMap() { arr = vector<Node *>(prime, new Node(-1, -1)); }

  void put(int key, int value) {
    const int tmp = hash(key);
    Node *h = arr[tmp];
    Node *prev = nullptr;
    while (h) {
      if (h->key == key) {
        h->val = value;
        return;
      }
      prev = h;
      h = h->next;
    }
    prev->next = new Node(key, value);
  }

  int get(int key) {
    const int tmp = hash(key);
    Node *h = arr[tmp]->next;
    while (h) {
      if (h->key == key)
        return h->val;
      h = h->next;
    }
    return -1;
  }

  void remove(int key) {
    const int tmp = hash(key);
    Node *h = arr[tmp]->next;
    while (h) {
      if (h->key == key)
        h->val = -1;
      h = h->next;
    }
  }

private:
  struct Node {
    int key;
    int val;
    Node *next;
    Node(int k, int v) : key(k), val(v), next(nullptr) {}
  };

  static const int prime = 2003;
  vector<Node *> arr;
  static inline int hash(int key) {
    long long k = key;
    return (k * k) % prime;
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
