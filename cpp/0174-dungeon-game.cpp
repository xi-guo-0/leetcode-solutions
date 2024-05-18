#include <vector>
using namespace std;

class Solution {
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();

    dungeon[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);

    for (int r = m - 2; r >= 0; --r) {
      dungeon[r][n - 1] = max(1, dungeon[r + 1][n - 1] - dungeon[r][n - 1]);
    }

    for (int c = n - 2; c >= 0; --c) {
      dungeon[m - 1][c] = max(1, dungeon[m - 1][c + 1] - dungeon[m - 1][c]);
    }

    for (int r = m - 2; r >= 0; --r) {
      for (int c = n - 2; c >= 0; --c) {
        dungeon[r][c] =
            max(1, min(dungeon[r + 1][c], dungeon[r][c + 1]) - dungeon[r][c]);
      }
    }

    return dungeon[0][0];
  }
};
