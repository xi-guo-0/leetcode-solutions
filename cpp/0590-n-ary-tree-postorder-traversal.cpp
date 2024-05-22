/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  vector<int> postorder(const Node *root) {
    vector<int> result;
    stack<const Node *> s;
    s.push(root);
    if (!root) {
      return result;
    }
    while (!s.empty()) {
      const Node *t = s.top();
      s.pop();
      result.push_back(t->val);
      for (const auto &c : t->children)
        s.push(c);
    }
    return vector<int>(result.rbegin(), result.rend());
  }
};
