#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int numMusicPlaylists(int n, int goal, int k) {
    constexpr int MOD = 1000'000'007;
    vector<vector<long long>> dp(n + 1, vector<long long>(goal + 1));

    dp[0][0] = 1;

    for (int l = 1; l <= goal; ++l) {
      for (int m = 1; m <= n; ++m) {
        dp[m][l] += dp[m - 1][l - 1] * (n - m + 1);
        dp[m][l] %= MOD;

        if (m > k) {
          dp[m][l] += dp[m][l - 1] * (m - k);
          dp[m][l] %= MOD;
        }
      }
    }

    return dp[n][goal];
  }
};

int main() { return 0; }
