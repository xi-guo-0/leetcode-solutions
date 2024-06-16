#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int numPermsDISequence(string s) {
    int n = s.size();
    constexpr int MOD = 1'000'000'007;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (s[i - 1] == 'D') {

          for (int k = j; k <= i - 1; ++k) {
            dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
          }
        } else {

          for (int k = 0; k < j; ++k) {
            dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
          }
        }
      }
    }

    int result = 0;
    for (int j = 0; j <= n; ++j) {
      result = (result + dp[n][j]) % MOD;
    }

    return result;
  }
};

int main() { return 0; }
