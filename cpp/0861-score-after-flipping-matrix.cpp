#include <vector>

using namespace std;

class Solution {
public:
  int matrixScore(vector<vector<int>> &grid) {
    auto m = grid.size();
    auto n = grid[0].size();
    for (auto i = 0; i < m; ++i) {
      if (grid[i][0] == 0) {
        for (auto j = 0; j < n; ++j) {
          grid[i][j] = 1 - grid[i][j];
        }
      }
    }
    for (auto j = 1; j < n; ++j) {
      auto zeros = 0;
      auto ones = 0;
      for (auto i = 0; i < m; ++i) {
        if (grid[i][j] == 0) {
          zeros += 1;
        } else {
          ones += 1;
        }
      }
      if (ones < zeros) {
        for (auto i = 0; i < m; ++i) {
          grid[i][j] = 1 - grid[i][j];
        }
      }
    }
    auto ans = 0;
    for (auto i = 0; i < m; ++i) {
      auto t = 0;
      for (auto j = 0; j < n; ++j) {
        t <<= 1;
        t += grid[i][j];
      }
      ans += t;
    }
    return ans;
  }
};

int main() { return 0; }
