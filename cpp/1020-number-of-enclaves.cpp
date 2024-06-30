#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  int numEnclaves(vector<vector<int>> &grid) {
    if (grid.size() == 0 || grid[0].size() == 0) {
      return 0;
    }
    int m = grid.size();
    int n = grid[0].size();
    function<void(int, int)> dfs;
    dfs = [&dfs, &grid, &m, &n](int r, int c) {
      grid[r][c] = 0;
      if (0 < r && grid[r - 1][c])
        dfs(r - 1, c);
      if (r + 1 < m && grid[r + 1][c])
        dfs(r + 1, c);
      if (0 < c && grid[r][c - 1])
        dfs(r, c - 1);
      if (c + 1 < n && grid[r][c + 1])
        dfs(r, c + 1);
    };
    for (int j = 0; j < n; j++) {
      if (grid[0][j])
        dfs(0, j);
      if (grid[m - 1][j])
        dfs(m - 1, j);
    }
    for (int i = 0; i < m; i++) {
      if (grid[i][0])
        dfs(i, 0);
      if (grid[i][n - 1])
        dfs(i, n - 1);
    }
    int sum = 0;
    for (const auto &row : grid)
      for (const auto &col : row)
        sum += col;
    return sum;
  }
};

int main() { return 0; }
