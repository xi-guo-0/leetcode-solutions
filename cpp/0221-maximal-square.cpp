class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int maxSide = 0;
    if (matrix.empty() || matrix[0].empty()) {
      return maxSide;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> dp(
        rows, vector<int>(cols, 0)); // 2D vector with initial zeros

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (matrix[i][j] == '1') {
          if (i == 0 || j == 0) {
            dp[i][j] = 1;
          } else {
            dp[i][j] =
                min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
          }
          maxSide = max(maxSide, dp[i][j]);
        }
      }
    }

    return maxSide * maxSide;
  }
};
