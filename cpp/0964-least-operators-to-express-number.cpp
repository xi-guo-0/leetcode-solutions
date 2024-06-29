#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
  int leastOpsExpressTarget(int x, int target) {
    if (x > target) {
      return min(target * 2 - 1, (x - target) * 2);
    } else if (x == target) {
      return 0;
    } else {
      int64_t sums = x;
      int times = 0;
      while (sums < target) {
        times += 1;
        sums *= x;
      }
      if (sums == target) {
        return times;
      }
      int l = numeric_limits<int>::max();
      int r = numeric_limits<int>::max();
      if (sums - target < target) {
        l = leastOpsExpressTarget(x, sums - target) + times;
      }
      r = leastOpsExpressTarget(x, target - (sums / x)) + times - 1;
      return min(l, r) + 1;
    }
  }
};

int main() { return 0; }
