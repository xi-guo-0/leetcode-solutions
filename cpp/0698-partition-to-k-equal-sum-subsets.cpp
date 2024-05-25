#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (totalSum % k != 0)
      return false;

    int subsetSum = totalSum / k;
    int n = nums.size();

    vector<int> dp(1 << n, -1);
    dp[0] = 0;

    for (int mask = 0; mask < (1 << n); ++mask) {
      if (dp[mask] == -1)
        continue;
      for (int i = 0; i < n; ++i) {
        if (!(mask & (1 << i)) && dp[mask] + nums[i] <= subsetSum) {
          int newMask = mask | (1 << i);
          int newRemainder = (dp[mask] + nums[i]) % subsetSum;
          if (newRemainder == 0)
            dp[newMask] = 0;
          else if (dp[newMask] == -1 || dp[newMask] > newRemainder)
            dp[newMask] = newRemainder;
        }
      }
    }

    return dp[(1 << n) - 1] == 0;
  }
};
