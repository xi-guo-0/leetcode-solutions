#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> powerfulIntegers(int x, int y, int bound) {
    unordered_set<int> unique_nums;

    if (bound < 1)
      return {};

    int max_i = (x > 1) ? static_cast<int>(log(bound) / log(x)) : 0;
    int max_j = (y > 1) ? static_cast<int>(log(bound) / log(y)) : 0;

    for (int i = 0; i <= max_i; ++i) {
      for (int j = 0; j <= max_j; ++j) {
        int value = pow(x, i) + pow(y, j);
        if (value <= bound) {
          unique_nums.insert(value);
        } else {
          break;
        }
        if (y == 1)
          break;
      }
      if (x == 1)
        break;
    }

    vector<int> result(unique_nums.begin(), unique_nums.end());
    sort(result.begin(), result.end());
    return result;
  }
};

int main() { return 0; }
