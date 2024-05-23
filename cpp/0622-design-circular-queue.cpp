class MyCircularQueue {
public:
  MyCircularQueue(int k) : k(k) {}

  bool enQueue(int value) {
    if (k <= q.size())
      return false;
    q.push(value);
    return true;
  }

  bool deQueue() {
    if (q.empty())
      return false;
    q.pop();
    return true;
  }

  int Front() {
    if (q.empty())
      return -1;
    return q.front();
  }

  int Rear() {
    if (q.empty())
      return -1;
    return q.back();
  }

  bool isEmpty() { return q.empty(); }

  bool isFull() { return k <= q.size(); }

private:
  queue<int> q;
  const int k;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
