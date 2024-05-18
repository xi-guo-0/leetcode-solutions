class Solution {
public:
  int coinChange(const vector<int> &coins, const int amount) {
    if (amount == 0)
      return 0;
    vector<int> dp(amount + 1, INT_MAX);
    for (int i = 0; i <= amount; i++) {
      int t = INT_MAX;
      for (int j = 0; j < coins.size(); j++) {
        int cost = INT_MAX;
        if (0 == i - coins[j]) {
          cost = 1;
        } else if (0 < i - coins[j] && dp[i - coins[j]] != INT_MAX) {
          cost = dp[i - coins[j]] + 1;
        }
        t = min(t, cost);
      }
      dp[i] = t;
    }
    return dp.back() == INT_MAX ? -1 : dp.back();
  }
};
