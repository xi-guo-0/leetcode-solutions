class Solution {
public:
  int longestPalindromeSubseq(const string &s) {
    const int n = s.size();
    vector<int> dp(n, 1);
    for (int i = n - 1; 0 <= i; --i) {
      int prev = 0;
      for (int j = i + 1; j < n; ++j) {
        int temp = dp[j];
        if (s[i] == s[j])
          dp[j] = 2 + prev;
        else
          dp[j] = max(dp[j], dp[j - 1]);
        prev = temp;
      }
    }
    return dp.back();
  }
};
