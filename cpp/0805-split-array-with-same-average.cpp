#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool splitArraySameAverage(vector<int> &nums) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    bool possible = false;
    for (int len = 1; len <= n / 2; ++len) {
      if ((totalSum * len) % n == 0) {
        possible = true;
        break;
      }
    }
    if (!possible)
      return false;

    vector<unordered_map<int, bool>> dp(n / 2 + 1);
    dp[0][0] = true;

    for (int num : nums) {
      for (int len = n / 2; len >= 1; --len) {
        for (auto &[sum, _] : dp[len - 1]) {
          dp[len][sum + num] = true;
        }
      }
    }

    for (int len = 1; len <= n / 2; ++len) {
      if ((totalSum * len) % n == 0 && dp[len].count((totalSum * len) / n)) {
        return true;
      }
    }

    return false;
  }
};

int main() { return 0; }
