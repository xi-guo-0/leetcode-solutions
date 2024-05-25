#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr array<array<int, 2>, 4> dir = {{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};

using T = array<int, 3>;

struct customGreater {
  bool operator()(const T &l, const T &r) const { return l[2] > r[2]; }
};

class Solution {
public:
  int cutOffTree(vector<vector<int>> &forest) {
    if (forest.empty() || forest[0].empty())
      return 0;
    int m = forest.size(), n = forest[0].size();

    priority_queue<T, vector<T>, customGreater> pq;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (forest[i][j] > 1)
          pq.push({i, j, forest[i][j]});

    array<int, 2> start = {0, 0};
    int sum = 0;
    while (!pq.empty()) {
      auto [x, y, height] = pq.top();
      pq.pop();
      int step = minStep(forest, start, {x, y, height}, m, n);
      if (step < 0)
        return -1;
      sum += step;
      start = {x, y};
    }

    return sum;
  }

private:
  int minStep(const vector<vector<int>> &forest, array<int, 2> start,
              array<int, 3> tree, int m, int n) {
    int step = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<array<int, 2>> q;
    q.push(start);
    visited[start[0]][start[1]] = true;

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        auto [r, c] = q.front();
        q.pop();
        if (r == tree[0] && c == tree[1])
          return step;

        for (const auto &d : dir) {
          int nr = r + d[0];
          int nc = c + d[1];
          if (nr < 0 || nr >= m || nc < 0 || nc >= n || forest[nr][nc] == 0 ||
              visited[nr][nc])
            continue;
          q.push({nr, nc});
          visited[nr][nc] = true;
        }
      }
      ++step;
    }

    return -1;
  }
};
