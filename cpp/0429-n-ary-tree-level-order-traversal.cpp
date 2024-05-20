/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> result;
    queue<Node *> current, next;

    if (root == nullptr) {
      return result;
    } else {
      current.push(root);
    }

    while (!current.empty()) {
      vector<int> level;
      while (!current.empty()) {
        Node *node = current.front();
        current.pop();
        level.push_back(node->val);
        for (auto &c : node->children)
          next.push(c);
      }
      result.push_back(move(level));
      swap(current, next);
    }
    return result;
  }
};
