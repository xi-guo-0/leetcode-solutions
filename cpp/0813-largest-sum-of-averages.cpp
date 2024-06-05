#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  double largestSumOfAverages(vector<int> &nums, int k) {
    int n = nums.size();
    vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0.0));
    vector<double> prefixSum(n + 1, 0.0);

    for (int i = 0; i < n; ++i) {
      prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    for (int i = 1; i <= n; ++i) {
      dp[i][1] = prefixSum[i] / i;
    }

    for (int j = 2; j <= k; ++j) {
      for (int i = 1; i <= n; ++i) {
        for (int p = 0; p < i; ++p) {
          dp[i][j] = max(dp[i][j], dp[p][j - 1] +
                                       (prefixSum[i] - prefixSum[p]) / (i - p));
        }
      }
    }

    return dp[n][k];
  }
};

int main() { return 0; }
