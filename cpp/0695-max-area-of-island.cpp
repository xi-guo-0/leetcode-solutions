class Solution {
  int countArea(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
        grid[i][j] != 1) {
      return 0;
    }
    grid[i][j] = 0;
    return 1 + countArea(grid, i + 1, j) + countArea(grid, i, j + 1) +
           countArea(grid, i - 1, j) + countArea(grid, i, j - 1);
  }

public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        ans = max(ans, countArea(grid, i, j));
      }
    }
    return ans;
  }
};
