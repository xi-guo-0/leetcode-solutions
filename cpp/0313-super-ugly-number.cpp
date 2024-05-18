#include <algorithm>
#include <cstdint>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    vector<uint64_t> dp(n, 1);
    vector<size_t> index(primes.size(), 0);
    for (int i = 1; i < n; i++) {
      auto ans = numeric_limits<uint64_t>::max();
      for (int j = 0; j < primes.size(); j++) {
        ans = min(ans, primes[j] * dp[index[j]]);
      }
      for (int j = 0; j < primes.size(); j++) {
        if (primes[j] * dp[index[j]] <= ans)
          ++index[j];
      }
      dp[i] = ans;
    }
    return dp.back();
  }
};
