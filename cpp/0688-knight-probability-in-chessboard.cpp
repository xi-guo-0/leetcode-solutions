#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double knightProbability(int n, int k, int row, int column) {
    vector<vector<double>> dp1(n, vector<double>(n, 1));
    vector<vector<double>> dp2(n, vector<double>(n, 0));

    int dr[] = {2, 2, 1, 1, -1, -1, -2, -2};
    int dc[] = {1, -1, 2, -2, 2, -2, 1, -1};

    for (int move = 0; move < k; ++move) {
      for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
          for (int dir = 0; dir < 8; ++dir) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
              dp2[nr][nc] += dp1[r][c] / 8.0;
            }
          }
        }
      }
      dp1.swap(dp2);
      fill(dp2.begin(), dp2.end(), vector<double>(n, 0));
    }

    return dp1[row][column];
  }
};
