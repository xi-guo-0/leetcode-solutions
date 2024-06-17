#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int snakesAndLadders(vector<vector<int>> &board) {
    int n = board.size();
    vector<int> flattenedBoard(n * n + 1);

    bool leftToRight = true;
    int index = 1;
    for (int i = n - 1; i >= 0; --i) {
      if (leftToRight) {
        for (int j = 0; j < n; ++j) {
          flattenedBoard[index++] = board[i][j];
        }
      } else {
        for (int j = n - 1; j >= 0; --j) {
          flattenedBoard[index++] = board[i][j];
        }
      }
      leftToRight = !leftToRight;
    }

    queue<int> q;
    q.push(1);
    vector<bool> visited(n * n + 1, false);
    visited[1] = true;
    int moves = 0;

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        int current = q.front();
        q.pop();

        if (current == n * n) {
          return moves;
        }

        for (int dice = 1; dice <= 6; ++dice) {
          int next = current + dice;
          if (next <= n * n && !visited[next]) {
            visited[next] = true;
            if (flattenedBoard[next] != -1) {
              q.push(flattenedBoard[next]);
            } else {
              q.push(next);
            }
          }
        }
      }
      ++moves;
    }

    return -1;
  }
};

int main() { return 0; }
