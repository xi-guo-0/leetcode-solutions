class Solution {
public:
  long long splitArray(const vector<int> &nums, const int m) {
    const int64_t n = nums.size();
    vector<vector<int64_t>> dp(
        n + 1, vector<int64_t>(m + 1, numeric_limits<int64_t>::max()));
    vector<int64_t> sub(n + 1, 0);
    for (int64_t i = 0; i < n; i++) {
      sub[i + 1] = sub[i] + nums[i];
    }
    dp[0][0] = 0;
    for (int64_t i = 1; i <= n; i++) {
      for (int64_t j = 1; j <= m; j++) {
        for (int64_t k = 0; k < i; k++) {
          dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sub[i] - sub[k]));
        }
      }
    }
    return dp[n][m];
  }
};
