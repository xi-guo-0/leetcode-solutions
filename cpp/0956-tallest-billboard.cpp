#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int tallestBillboard(vector<int> &rods) {
    unordered_map<int, int> dp;
    dp[0] = 0;

    for (int rod : rods) {
      auto current_dp = dp;

      for (auto &[diff, height] : current_dp) {
        dp[diff] = max(dp[diff], height);

        dp[diff + rod] = max(dp[diff + rod], height);

        if (diff >= rod) {
          dp[diff - rod] = max(dp[diff - rod], height + rod);
        } else {
          dp[rod - diff] = max(dp[rod - diff], height + diff);
        }
      }
    }

    return dp[0];
  }
};

int main() { return 0; }
