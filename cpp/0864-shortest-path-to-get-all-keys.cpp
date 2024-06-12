#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct State {
  int x, y, keys;
  State(int x, int y, int keys) : x(x), y(y), keys(keys) {}
};

struct StateHash {
  size_t operator()(const State &s) const {
    return hash<int>()(s.x) ^ hash<int>()(s.y) ^ hash<int>()(s.keys);
  }
};

struct StateEqual {
  bool operator()(const State &a, const State &b) const {
    return a.x == b.x && a.y == b.y && a.keys == b.keys;
  }
};

const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
public:
  int shortestPathAllKeys(vector<string> &grid) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<State, int>> q;
    unordered_set<State, StateHash, StateEqual> visited;

    int all_keys = 0;
    State start(0, 0, 0);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        char c = grid[i][j];
        if (c == '@') {
          start = State(i, j, 0);
        }
        if (c >= 'a' && c <= 'f') {
          all_keys |= (1 << (c - 'a'));
        }
      }
    }

    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
      auto [current, steps] = q.front();
      q.pop();

      if (current.keys == all_keys) {
        return steps;
      }

      for (auto &[dx, dy] : directions) {
        int nx = current.x + dx;
        int ny = current.y + dy;
        int nkeys = current.keys;

        if (nx < 0 || ny < 0 || nx >= m || ny >= n)
          continue;
        char c = grid[nx][ny];

        if (c == '#')
          continue;

        if (c >= 'a' && c <= 'f') {
          nkeys |= (1 << (c - 'a'));
        }

        if (c >= 'A' && c <= 'F' && !(nkeys & (1 << (c - 'A')))) {
          continue;
        }

        State next(nx, ny, nkeys);
        if (!visited.count(next)) {
          visited.insert(next);
          q.push({next, steps + 1});
        }
      }
    }

    return -1;
  }
};

int main() { return 0; }
