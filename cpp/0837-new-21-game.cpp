#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
  double new21Game(int n, int k, int maxPts) {
    if (k == 0) {
      return 1.0;
    }
    vector<double> dp(n + maxPts);
    for (int i = k; i <= n && i < k + maxPts; ++i) {
      dp[i] = 1.0;
    }
    dp[k - 1] = 1.0 * std::min(n - k + 1, maxPts) / maxPts;
    for (int i = k - 2; i >= 0; --i) {
      dp[i] = dp[i + 1] - (dp[i + maxPts + 1] - dp[i + 1]) / maxPts;
    }
    return dp[0];
  }
};

int main() { return 0; }
