#include <set>
#include <utility>
#include <vector>

using namespace std;

/*  8 1 6   8 3 4   6 1 8   6 7 2
    3 5 7   1 5 9   7 5 3   1 5 9
    4 9 2   6 7 2   2 9 4   8 3 4

    4 9 2   4 3 8   2 9 4   2 7 6
    3 5 7   9 5 1   7 5 3   9 5 1
    8 1 6   2 7 6   6 1 8   4 3 8
*/
class Solution {
public:
  int numMagicSquaresInside(const vector<vector<int>> &grid) {
    const set<int> s{816357492, 834159672, 618753294, 672159834,
                     492357816, 438951276, 294753618, 276951438};
    const vector<pair<int, int>> change{{-2, -2}, {-2, -1}, {-2, 0},
                                        {-1, -2}, {-1, -1}, {-1, 0},
                                        {0, -2},  {0, -1},  {0, 0}};
    int result = 0;
    for (int i = 2; i < grid.size(); i++) {
      for (int j = 2; j < grid.size(); j++) {
        int sum = 0;
        for (int k = 0; k < 9; k++) {
          sum *= 10;
          sum += grid[i + change[k].first][j + change[k].second];
        }
        if (s.find(sum) != s.end())
          result++;
      }
    }
    return result;
  }
};

int main() { return 0; }
