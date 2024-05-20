class Solution {
public:
  int change(const int amount, vector<int> &coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (const auto &coin : coins)
      for (int j = 0; j <= amount; ++j)
        if (0 <= j - coin)
          dp[j] += dp[j - coin];
    return dp[amount];
  }
};
