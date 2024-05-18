class Solution {
public:
  int countPrimes(int n) {
    vector<bool> dp(n + 1, true);
    int result = 0;
    int i = 2;
    for (; i * i <= n; i++) {
      if (dp[i]) {
        result++;
        for (int j = 2 * i; j <= n; j += i) {
          dp[j] = false;
        }
      }
    }
    for (; i < n; i++)
      dp[i] ? result++ : 0;
    return result;
  }
};
