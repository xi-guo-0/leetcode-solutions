#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter,
                                        int cCenter) {

    vector<vector<int>> v(rows * cols, vector<int>(2, 0));
    generate(v.begin(), v.end(), [n = -1, &cols]() mutable {
      n++;
      return vector<int>{n / cols, n % cols};
    });
    sort(v.begin(), v.end(),
         [&rCenter, &cCenter](const vector<int> &a, const vector<int> &b) {
           return abs(a[0] - rCenter) + abs(a[1] - cCenter) <
                  abs(b[0] - rCenter) + abs(b[1] - cCenter);
         });
    return v;
  }
};

int main() { return 0; }
