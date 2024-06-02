#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> tower(101, vector<double>(101, 0.0));

    tower[0][0] = poured;

    for (int row = 0; row <= query_row; ++row) {
      for (int glass = 0; glass <= row; ++glass) {
        if (tower[row][glass] > 1.0) {
          double overflow = tower[row][glass] - 1.0;
          tower[row][glass] = 1.0;
          tower[row + 1][glass] += overflow / 2.0;
          tower[row + 1][glass + 1] += overflow / 2.0;
        }
      }
    }

    return tower[query_row][query_glass];
  }
};

int main() { return 0; }
