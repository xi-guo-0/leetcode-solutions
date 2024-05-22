#include <algorithm>
#include <vector>

class Solution {
public:
  int maxCount(int m, int n, std::vector<std::vector<int>> &ops) {
    for (const auto &op : ops) {
      if (m > op[0]) {
        m = op[0];
      }
      if (n > op[1]) {
        n = op[1];
      }
      if (1 == m && 1 == n) {
        break;
      }
    }
    return m * n;
  }
};
