/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  Node *cloneGraph(Node *node) {
    if (!node)
      return nullptr;
    unordered_map<const Node *, Node *> copied;
    clone(node, copied);
    return copied[node];
  }

private:
  Node *clone(const Node *node, unordered_map<const Node *, Node *> &copied) {
    if (copied.count(node))
      return copied[node];
    Node *cur = new Node(node->val);
    copied[node] = cur;
    for (auto &nbr : node->neighbors)
      cur->neighbors.push_back(clone(nbr, copied));
    return cur;
  }
};
