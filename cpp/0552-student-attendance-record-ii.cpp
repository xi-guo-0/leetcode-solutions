#include <iostream>
#include <vector>

using namespace std;

constexpr int MOD = 1000000007;

int modAdd(int a, int b) { return (a % MOD + b % MOD) % MOD; }

template <typename T, typename... Args> int modAdd(T first, Args... args) {
  return modAdd(first, modAdd(args...));
}

class Solution {
public:
  int checkRecord(int n) {
    vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>(2, vector<int>(3, 0)));
    dp[1][0][0] = dp[1][0][1] = dp[1][1][0] = 1;

    for (int i = 2; i <= n; ++i) {
      dp[i][0][0] = modAdd(dp[i - 1][0][0], dp[i - 1][0][1], dp[i - 1][0][2]);
      dp[i][0][1] = dp[i - 1][0][0];
      dp[i][0][2] = dp[i - 1][0][1];

      dp[i][1][0] = modAdd(dp[i - 1][0][0], dp[i - 1][0][1], dp[i - 1][0][2],
                           dp[i - 1][1][0], dp[i - 1][1][1], dp[i - 1][1][2]);

      dp[i][1][1] = dp[i - 1][1][0];
      dp[i][1][2] = dp[i - 1][1][1];
    }

    int total = 0;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 3; ++j) {
        total = modAdd(total, dp[n][i][j]);
      }
    }

    return total;
  }
};
