class Solution {
public:
  int dp[51][51][51];
  int64_t mod = 1000000007;

  int dfs(int i, int j, int n, int m, int moves) {
    if (i < 0 || i >= n || j < 0 || j >= m)
      return 1;
    if (moves <= 0)
      return 0;
    if (dp[i][j][moves] != -1)
      return dp[i][j][moves];

    return dp[i][j][moves] = ((dfs(i - 1, j, n, m, moves - 1) % mod +
                               dfs(i + 1, j, n, m, moves - 1) % mod +
                               dfs(i, j - 1, n, m, moves - 1) % mod +
                               dfs(i, j + 1, n, m, moves - 1) % mod) %
                              mod);
  }

  int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
    memset(dp, -1, sizeof(dp));
    return dfs(startRow, startColumn, n, m, maxMove);
  }
};
