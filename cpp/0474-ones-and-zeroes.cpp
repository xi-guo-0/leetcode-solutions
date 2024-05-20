class Solution {
public:
  int findMaxForm(const vector<string> &strs, const int m, const int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (const auto &str : strs) {
      int zero = 0, one = 0;
      for (const auto &ch : str)
        ch == '0' ? ++zero : ++one;
      for (int i = m; zero <= i; --i)
        for (int j = n; one <= j; --j)
          dp[i][j] = max(dp[i][j], 1 + dp[i - zero][j - one]);
    }
    return dp[m][n];
  }
};
