class Solution {
public:
  int nthUglyNumber(const int n) {
    vector<int> dp(n, 0);
    int index_2 = 0, index_3 = 0, index_5 = 0;
    dp.front() = 1;
    for (int i = 1; i < n; i++) {
      dp[i] = min(min(2 * dp[index_2], 3 * dp[index_3]), 5 * dp[index_5]);
      if (2 * dp[index_2] <= dp[i])
        index_2++;
      if (3 * dp[index_3] <= dp[i])
        index_3++;
      if (5 * dp[index_5] <= dp[i])
        index_5++;
    }
    return dp.back();
  }
};
