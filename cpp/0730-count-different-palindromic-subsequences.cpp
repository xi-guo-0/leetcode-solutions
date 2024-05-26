#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int MOD = 1000000007;

class Solution {
public:
  int countPalindromicSubsequences(string s) {
    int n = s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(4)));

    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        for (int k = 0; k < 4; ++k) {
          char c = 'a' + k;
          if (i == j) {
            dp[i][j][k] = (s[i] == c);
          } else {
            if (s[i] != c)
              dp[i][j][k] = dp[i + 1][j][k];
            else if (s[j] != c)
              dp[i][j][k] = dp[i][j - 1][k];
            else {
              dp[i][j][k] = 2;
              for (int l = 0; l < 4; ++l) {
                dp[i][j][k] = (dp[i][j][k] + dp[i + 1][j - 1][l]) % MOD;
              }
            }
          }
        }
      }
    }

    int total = 0;
    for (int k = 0; k < 4; ++k) {
      total = (total + dp[0][n - 1][k]) % MOD;
    }
    return total;
  }
};

int main() {
  string s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";
  Solution solution;
  cout << solution.countPalindromicSubsequences(s) << endl;
  return 0;
}
