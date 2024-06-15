#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int projectionArea(vector<vector<int>> &grid) {
    if (grid.size() == 0 || grid[0].size() == 0) {
      return 0;
    }
    int m = grid.size();
    int n = grid[0].size();
    int sxy = 0;
    vector<int> mxz(m, 0);
    vector<int> myz(n, 0);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] != 0) {
          sxy++;
          mxz[i] = max(mxz[i], grid[i][j]);
          myz[j] = max(myz[j], grid[i][j]);
        }
      }
    }
    int sum = sxy;
    for (auto i : mxz)
      sum += i;
    for (auto j : myz)
      sum += j;
    return sum;
  }
};

int main() { return 0; }
