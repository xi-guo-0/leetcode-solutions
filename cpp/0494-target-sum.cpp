class Solution {
public:
  int findTargetSumWays(const vector<int> &nums, const int S) {
    array<int, 2001> dp;
    fill(dp.begin(), dp.end(), 0);
    dp[nums[0] + 1000] = 1;
    dp[-nums[0] + 1000] += 1;
    for (int i = 1; i < nums.size(); ++i) {
      array<int, 2001> next;
      fill(next.begin(), next.end(), 0);
      for (int j = 0; j <= 2000; ++j) {
        if (0 < dp[j]) {
          next[j + nums[i]] += dp[j];
          next[j - nums[i]] += dp[j];
        }
      }
      dp = next;
    }
    return 1000 < S ? 0 : dp[S + 1000];
  }
};
