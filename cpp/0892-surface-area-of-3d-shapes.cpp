#include <vector>

using namespace std;

class Solution {
public:
  int surfaceArea(const vector<vector<int>> &grid) {
    if (grid.size() == 0 || grid[0].size() == 0) {
      return 0;
    }
    auto profileArea = [&grid](int i, int j) {
      const int m = grid[i][j];
      const int u = 0 < i ? grid[i - 1][j] : 0;
      const int d = i < grid.size() - 1 ? grid[i + 1][j] : 0;
      const int l = 0 < j ? grid[i][j - 1] : 0;
      const int r = j < grid[0].size() - 1 ? grid[i][j + 1] : 0;
      return max(m - u, 0) + max(m - d, 0) + max(m - l, 0) + max(m - r, 0);
    };
    auto updownArea = [&grid](int i, int j) { return grid[i][j] ? 2 : 0; };
    int sum = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        sum += profileArea(i, j) + updownArea(i, j);
      }
    }
    return sum;
  }
};

int main() { return 0; }
