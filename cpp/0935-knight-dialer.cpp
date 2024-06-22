#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int knightDialer(int n) {
    if (n == 0)
      return 0;
    if (n == 1)
      return 10;

    constexpr int MOD = 1e9 + 7;

    vector<vector<int>> moves = {{4, 6}, {6, 8},    {7, 9}, {4, 8}, {0, 3, 9},
                                 {},     {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

    vector<int> dp(10, 1);

    for (int step = 2; step <= n; ++step) {
      vector<int> next_dp(10);
      for (int i = 0; i < 10; ++i) {
        for (int next : moves[i]) {
          next_dp[next] = (next_dp[next] + dp[i]) % MOD;
        }
      }
      dp = next_dp;
    }

    int total_ways = 0;
    for (int count : dp) {
      total_ways = (total_ways + count) % MOD;
    }

    return total_ways;
  }
};

int main() { return 0; }
