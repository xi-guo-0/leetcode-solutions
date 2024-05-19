#include <cstddef>
#include <cstdint>
#include <vector>

using namespace std;

class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    int64_t dp[sz]{};
    dp[0] = 1;
    for (size_t i = 1; i <= target; ++i) {
      for (const auto x : nums) {
        const size_t y = x;
        if (y <= i) {
          dp[i] += dp[i - y];
          dp[i] &= 0xffffffff;
        }
      }
    }
    return dp[target];
  }

private:
  static constexpr size_t sz = 1024;
};
