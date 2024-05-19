#include <algorithm>
#include <cstddef>
#include <iostream>
#include <limits>
#include <numeric>

using namespace std;

class Solution {
public:
  int getMoneyAmount(int n) {
    int dp[sz][sz]{};
    for (int len = 2; len <= n; ++len) {
      for (int start = 1; start <= n - len + 1; ++start) {
        int end = start + len - 1;
        dp[start][end] = numeric_limits<int>::max();
        for (int guess = start; guess <= end; ++guess) {
          int cost = guess + max(dp[start][guess - 1], dp[guess + 1][end]);
          dp[start][end] = min(dp[start][end], cost);
        }
      }
    }

    return dp[1][n];
  }

private:
  static size_t constexpr sz = 256;
};

int main() {
  Solution solution;
  for (int i = 1; i <= 10; ++i) {
    cout << solution.getMoneyAmount(i) << endl;
  }
  return 0;
}
