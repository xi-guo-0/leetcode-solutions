#include <vector>

using namespace std;

class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    int dp[400] = {0};
    for (auto it = days.rbegin(); it != days.rend(); it++) {
      const int i = *it;
      int j = next(it) == days.rend() ? 0 : (*next(it));
      const int val = min(min(dp[i + 1] + costs[0], dp[i + 7] + costs[1]),
                          dp[i + 30] + costs[2]);
      for (; j <= i; j++)
        dp[j] = val;
    }
    return dp[days.front()];
  }
};

int main() { return 0; }
