#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int strangePrinter(string s) {
    int n = s.length();
    if (n == 0)
      return 0;

    std::vector<std::vector<int>> dp(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
    }

    for (int len = 2; len <= n; ++len) {
      for (int i = 0; i + len - 1 < n; ++i) {
        int j = i + len - 1;
        dp[i][j] = dp[i][j - 1] + 1;
        for (int k = i; k < j; ++k) {
          if (s[k] == s[j]) {
            dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j - 1]);
          }
        }
      }
    }

    return dp[0][n - 1];
  }
};
