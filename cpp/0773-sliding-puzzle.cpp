#include <algorithm>
#include <functional>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int slidingPuzzle(vector<vector<int>> &board) {
    const vector<vector<int>> dir = {{1, 3}, {0, 2, 4}, {1, 5},
                                     {0, 4}, {1, 3, 5}, {2, 4}};
    const vector<int> endBoard = {1, 2, 3, 4, 5, 0};

    Node curr(board);
    if (curr.board == endBoard)
      return 0;

    priority_queue<Node, vector<Node>, greater<>> queue;
    queue.push(curr);
    unordered_set<Node, Node::Hash, Node::Equal> visited;
    visited.insert(curr);

    while (!queue.empty()) {
      curr = queue.top();
      queue.pop();
      for (int nextZeroPos : dir[curr.zeroPos]) {
        vector<int> nextBoard = curr.board;
        swap(nextBoard[curr.zeroPos], nextBoard[nextZeroPos]);
        if (nextBoard == endBoard)
          return curr.count + 1;
        Node next(nextBoard, nextZeroPos, curr.count + 1);
        if (visited.find(next) != visited.end())
          continue;
        queue.push(next);
        visited.insert(next);
      }
    }
    return -1;
  }

private:
  struct Node {
    vector<int> board;
    int zeroPos;
    int count;
    int distance;
    int f;

    Node(const vector<vector<int>> &board) : count(0) {
      this->board.resize(6);
      for (int i = 0; i < 6; ++i) {
        this->board[i] = board[i / 3][i % 3];
        if (this->board[i] == 0)
          this->zeroPos = i;
      }
      this->distance = calcDistance();
      this->f = this->count + this->distance;
    }

    Node(const vector<int> &board, int zeroPos, int count)
        : board(board), zeroPos(zeroPos), count(count) {
      this->distance = calcDistance();
      this->f = this->count + this->distance;
    }

    int calcDistance() const {
      int dist = 0;
      for (int i = 0; i < 6; ++i) {
        int v = board[i] - 1;
        if (v == -1)
          continue;
        dist += abs(v / 3 - i / 3) + abs(v % 3 - i % 3);
      }
      return dist;
    }

    bool operator>(const Node &other) const { return this->f > other.f; }

    bool operator==(const Node &other) const {
      return zeroPos == other.zeroPos && board == other.board;
    }

    struct Hash {
      size_t operator()(const Node &node) const {
        size_t result = hash<int>{}(node.zeroPos);
        for (int num : node.board) {
          result = result * 31 + hash<int>{}(num);
        }
        return result;
      }
    };

    struct Equal {
      bool operator()(const Node &lhs, const Node &rhs) const {
        return lhs == rhs;
      }
    };
  };
};

int main() { return 0; }
