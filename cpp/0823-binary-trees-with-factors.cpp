#include <algorithm>
#include <cstddef>
#include <ranges>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int numFactoredBinaryTrees(vector<int> &arr) {
    constexpr int MOD = 1'000'000'007;
    ranges::sort(arr);
    unordered_map<int, long> dp;
    for (const int &num : arr) {
      dp[num] = 1;
    }

    for (size_t i = 0; i < arr.size(); ++i) {
      for (size_t j = 0; j < i; ++j) {
        if (arr[i] % arr[j] == 0) {
          int right = arr[i] / arr[j];
          if (dp.count(right)) {
            dp[arr[i]] = (dp[arr[i]] + (dp[arr[j]] * dp[right]) % MOD) % MOD;
          }
        }
      }
    }

    long ans = 0;
    for (const auto &[key, value] : dp) {
      ans = (ans + value) % MOD;
    }
    return static_cast<int>(ans);
  }
};

int main() { return 0; }
