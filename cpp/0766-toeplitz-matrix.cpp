#include <vector>

using namespace std;

class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    for (int d = 1 - n; d < m; ++d) {
      int r = max(0, d);
      int c = r - d;
      int t = matrix[r][c];
      for (int i = r, j = c; i < m && j < n; ++i, ++j) {
        if (t != matrix[i][j]) {
          return false;
        }
      }
    }
    return true;
  }
};

int main() { return 0; }
