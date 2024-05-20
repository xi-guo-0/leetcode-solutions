#include <vector>

class Solution {
public:
  int islandPerimeter(std::vector<std::vector<int>> &grid) {
    int perimeter = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (1 == grid[i][j]) {
          if (0 == i || 0 == grid[i - 1][j]) {
            perimeter++;
          }
          if (0 == j || 0 == grid[i][j - 1]) {
            perimeter++;
          }
          if (m - 1 <= i || 0 == grid[i + 1][j]) {
            perimeter++;
          }
          if (n - 1 <= j || 0 == grid[i][j + 1]) {
            perimeter++;
          }
        }
      }
    }
    return perimeter;
  }
};
