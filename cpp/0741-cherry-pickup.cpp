#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int cherryPickup(vector<vector<int>> &grid) {
    int N = grid.size();
    vector<vector<vector<int>>> memo(
        N, vector<vector<int>>(N, vector<int>(N, -1)));

    auto dp = [&](auto &&self, int r1, int c1, int c2) -> int {
      int r2 = r1 + c1 - c2;
      if (r1 >= N || c1 >= N || r2 >= N || c2 >= N || grid[r1][c1] == -1 ||
          grid[r2][c2] == -1) {
        return INT_MIN;
      }
      if (r1 == N - 1 && c1 == N - 1) {
        return grid[r1][c1];
      }
      if (memo[r1][c1][c2] != -1) {
        return memo[r1][c1][c2];
      }
      int result = grid[r1][c1];
      if (c1 != c2) {
        result += grid[r2][c2];
      }
      result +=
          max({self(self, r1, c1 + 1, c2 + 1), self(self, r1 + 1, c1, c2 + 1),
               self(self, r1, c1 + 1, c2), self(self, r1 + 1, c1, c2)});
      memo[r1][c1][c2] = result;
      return result;
    };

    return max(0, dp(dp, 0, 0, 0));
  }
};

int main() {
  vector<vector<int>> grid = {{0, 1, -1}, {1, 0, -1}, {1, 1, 1}};
  Solution sol;
  cout << sol.cherryPickup(grid) << endl;
  return 0;
}
