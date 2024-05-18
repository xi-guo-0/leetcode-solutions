class Solution {
public:
  int numDistinct(const string &s, const string &t) {
    if (s.empty() || t.empty())
      return 0;
    const int m = t.size(), n = s.size();
    long long dp[1024][1024] = {{0}};
    for (int j = 0; j <= n; j++)
      dp[0][j] = 1;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        if (t[i - 1] == s[j - 1])
          dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % (1000000007);
        else
          dp[i][j] = dp[i][j - 1];
    return dp[m][n];
  }
};
