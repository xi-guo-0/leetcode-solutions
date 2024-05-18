class Solution {
public:
  bool isInterleave(const string &s1, const string &s2, const string &s3) {
    const int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    if (n1 + n2 != n3)
      return false;
    vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= n1; i++) {
      for (int j = 0; j <= n2; j++) {
        if (0 < i && s1[i - 1] == s3[i + j - 1])
          dp[i][j] = dp[i][j] || dp[i - 1][j];
        if (0 < j && s2[j - 1] == s3[i + j - 1])
          dp[i][j] = dp[i][j] || dp[i][j - 1];
      }
    }
    return dp[n1][n2];
  }
};
