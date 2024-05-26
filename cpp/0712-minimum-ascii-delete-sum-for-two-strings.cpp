#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumDeleteSum(const string &s1, const string &s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1, sum = 0; i <= m; i++)
      dp[i][0] = sum += s1[i - 1];
    for (int j = 1, sum = 0; j <= n; j++)
      dp[0][j] = sum += s2[j - 1];

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          const int a = s1[i - 1] + dp[i - 1][j];
          const int b = s2[j - 1] + dp[i][j - 1];
          dp[i][j] = min(a, b);
        }
      }
    }

    return dp[m][n];
  }
};
