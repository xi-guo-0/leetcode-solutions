class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    s.push(x);
    if (m.empty() || x <= m.top())
      m.push(x);
  }

  void pop() {
    if (!m.empty() && m.top() == s.top())
      m.pop();
    s.pop();
  }

  int top() { return s.top(); }

  int getMin() { return m.top(); }

private:
  stack<int> s;
  stack<int> m;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
