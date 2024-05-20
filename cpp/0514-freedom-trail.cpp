#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int findRotateSteps(string ring, string key) {
    int n = ring.size(), m = key.size();
    vector<vector<int>> dp(m + 1, vector<int>(n, numeric_limits<int>::max()));

    for (int i = 0; i < n; ++i) {
      if (ring[i] == key[0]) {
        dp[0][i] = min(i, n - i) + 1;
      }
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (ring[j] == key[i]) {
          for (int k = 0; k < n; ++k) {
            if (dp[i - 1][k] != numeric_limits<int>::max()) {
              int diff = abs(j - k);
              dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(diff, n - diff) + 1);
            }
          }
        }
      }
    }

    int result = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
      result = min(result, dp[m - 1][i]);
    }

    return result;
  }
};
