#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
    if (M.empty())
      return {};
    int m = M.size(), n = M[0].size();
    vector<vector<int>> result(m, vector<int>(n));
    vector<pair<int, int>> dir{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0},
                               {0, 1},   {1, -1}, {1, 0},  {1, 1}};
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        double value = 0.0;
        int count = 0;
        for (const auto &d : dir) {
          int x = i + d.first, y = j + d.second;
          if (x >= 0 && x < m && y >= 0 && y < n) {
            value += M[x][y];
            count++;
          }
        }
        result[i][j] = floor(value / count);
      }
    }
    return result;
  }
};
