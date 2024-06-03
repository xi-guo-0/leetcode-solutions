#include <vector>

using namespace std;

class Solution {
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
    int count = 0;
    int top_max[64] = {0};
    int left_max[64] = {0};
    int tmp = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] > top_max[j])
          top_max[j] = grid[i][j];
        if (grid[i][j] > left_max[i])
          left_max[i] = grid[i][j];
      }
    }
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        tmp = min(top_max[j], left_max[i]);
        if (grid[i][j] < tmp)
          count += tmp - grid[i][j];
      }
    }
    return count;
  }
};

int main() { return 0; }
