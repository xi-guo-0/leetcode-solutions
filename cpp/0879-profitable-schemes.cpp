#include <vector>

using namespace std;

class Solution {
public:
  int profitableSchemes(int n, int minProfit, vector<int> &group,
                        vector<int> &profit) {
    constexpr int MOD = 1'000'000'007;
    int len = group.size();

    vector<vector<int>> dp(minProfit + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int k = 0; k < len; ++k) {
      int g = group[k];
      int p = profit[k];

      for (int i = minProfit; i >= 0; --i) {
        for (int j = n - g; j >= 0; --j) {
          int newProfit = min(i + p, minProfit);
          dp[newProfit][j + g] = (dp[newProfit][j + g] + dp[i][j]) % MOD;
        }
      }
    }

    int totalSchemes = 0;
    for (int schemes : dp[minProfit]) {
      totalSchemes = (totalSchemes + schemes) % MOD;
    }

    return totalSchemes;
  }
};

int main() { return 0; }
