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
  Node *construct(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty()) {
      return nullptr;
    }
    this->grid = grid;
    return helper(0, 0, grid.size());
  }

private:
  std::vector<std::vector<int>> grid;

  Node *helper(int r, int c, int a) {
    bool allTrue = true;
    bool allFalse = true;
    for (int i = r; i < r + a; ++i) {
      for (int j = c; j < c + a; ++j) {
        if (grid[i][j] == 0) {
          allTrue = false;
        } else {
          allFalse = false;
        }
        if (!allTrue && !allFalse) {
          break;
        }
      }
    }
    if (allTrue) {
      return new Node(true, true);
    } else if (allFalse) {
      return new Node(false, true);
    } else {
      Node *ans = new Node(true, false);
      int b = a / 2;
      ans->topLeft = helper(r, c, b);
      ans->topRight = helper(r, c + b, b);
      ans->bottomLeft = helper(r + b, c, b);
      ans->bottomRight = helper(r + b, c + b, b);
      return ans;
    }
  }
};
