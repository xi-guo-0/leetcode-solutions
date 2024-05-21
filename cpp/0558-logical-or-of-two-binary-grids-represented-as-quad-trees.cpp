/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
public:
  Node *intersect(Node *q1, Node *q2) {
    if (q1->isLeaf && q2->isLeaf) {
      return new Node(q1->val || q2->val, true, nullptr, nullptr, nullptr,
                      nullptr);
    } else if (q1->isLeaf) {
      if (q1->val) {
        return q1;
      } else {
        return q2;
      }
    } else if (q2->isLeaf) {
      if (q2->val) {
        return q2;
      } else {
        return q1;
      }
    }
    Node *tl = intersect(q1->topLeft, q2->topLeft);
    Node *tr = intersect(q1->topRight, q2->topRight);
    Node *bl = intersect(q1->bottomLeft, q2->bottomLeft);
    Node *br = intersect(q1->bottomRight, q2->bottomRight);
    if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf) {
      if (tl->val && tr->val && bl->val && br->val) {
        return new Node(true, true, nullptr, nullptr, nullptr, nullptr);
      } else if (!tl->val && !tr->val && !bl->val && !br->val) {
        return new Node(false, true, nullptr, nullptr, nullptr, nullptr);
      }
    }
    return new Node(false, false, tl, tr, bl, br);
  }
};
