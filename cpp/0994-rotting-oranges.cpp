#include <vector>

using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    paint(grid);
    multi_source(grid);
    return collect(grid);
  }

private:
  static constexpr int inf = 999;
  static constexpr array<int, 4> dr{1, 0, -1, 0};
  static constexpr array<int, 4> dc{0, -1, 0, 1};

  void paint(vector<vector<int>> &grid) {
    for (auto &line : grid) {
      for (auto &e : line) {
        if (0 == e) {
          e = -1;
        } else if (2 == e) {
          e = 0;
        } else {
          e = inf;
        }
      }
    }
  }

  void bfs(vector<vector<int>> &grid, int m, int n, int r, int c, int steps) {
    grid[r][c] = steps;
    for (int k = 0; k < 4; ++k) {
      int nr = r + dr[k];
      int nc = c + dc[k];
      if (0 <= nr && nr < m && 0 <= nc && nc < n && 0 < grid[nr][nc] &&
          steps + 1 < grid[nr][nc]) {
        bfs(grid, m, n, nr, nc, steps + 1);
      }
    }
  }

  void multi_source(vector<vector<int>> &grid) {
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 0) {
          bfs(grid, grid.size(), grid[0].size(), i, j, 0);
        }
      }
    }
  }

  int collect(vector<vector<int>> &grid) {
    int ans = 0;
    for (const auto &line : grid) {
      for (const auto &e : line) {
        ans = max(ans, e);
      }
    }
    if (ans == inf) {
      return -1;
    } else {
      return ans;
    }
  }
};

int main() { return 0; }
