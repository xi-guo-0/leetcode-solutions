class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    if (grid.empty() || grid[0].empty())
      return 0;
    const int m = grid.size(), n = grid[0].size();
    int res = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] == land) {
          res++;
          dfs(grid, i, j);
        }
    return res;
  }

private:
  const char land = '1';
  const char water = '0';

  void dfs(vector<vector<char>> &grid, const int r, const int c) {
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};
    grid[r][c] = water;
    for (int i = 0; i < 4; i++) {
      const int nr = r + dr[i];
      const int nc = c + dc[i];
      if (0 <= nr && nr < grid.size() && 0 <= nc && nc < grid[0].size() &&
          grid[nr][nc] == land)
        dfs(grid, nr, nc);
    }
  }
};
