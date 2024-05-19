class Solution {
public:
  bool canCross(vector<int> const &stones) {
    int const n = stones.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    dp[0][1] = true;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        int const diff = stones[i] - stones[j];
        if (0 <= diff && diff < n && dp[j][diff]) {
          dp[i][diff] = true;
          if (0 <= diff - 1) {
            dp[i][diff - 1] = true;
          }
          if (diff + 1 < n) {
            dp[i][diff + 1] = true;
          }
        }
      }
    }
    return accumulate(dp.back().begin(), dp.back().end(), false,
                      logical_or<bool>());
  }
};
