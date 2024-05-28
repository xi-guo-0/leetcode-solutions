#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int orderOfLargestPlusSign(const int N, const vector<vector<int>> &mines) {
    vector<vector<int>> dp(N, vector<int>(N, N));
    set<pair<int, int>> banned;

    for (const auto &mine : mines)
      banned.insert({mine[0], mine[1]});

    for (int r = 0; r < N; ++r) {
      int count = 0;
      for (int c = 0; c < N; ++c) {
        count = banned.count({r, c}) ? 0 : count + 1;
        dp[r][c] = count;
      }
      count = 0;
      for (int c = N - 1; c >= 0; --c) {
        count = banned.count({r, c}) ? 0 : count + 1;
        dp[r][c] = min(dp[r][c], count);
      }
    }

    for (int c = 0; c < N; ++c) {
      int count = 0;
      for (int r = 0; r < N; ++r) {
        count = banned.count({r, c}) ? 0 : count + 1;
        dp[r][c] = min(dp[r][c], count);
      }
      count = 0;
      for (int r = N - 1; r >= 0; --r) {
        count = banned.count({r, c}) ? 0 : count + 1;
        dp[r][c] = min(dp[r][c], count);
      }
    }

    int res = 0;
    for (int r = 0; r < N; ++r) {
      for (int c = 0; c < N; ++c) {
        res = max(res, dp[r][c]);
      }
    }

    return res;
  }
};

int main() { return 0; }
