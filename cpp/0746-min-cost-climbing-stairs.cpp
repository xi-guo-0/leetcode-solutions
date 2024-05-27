#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int minCostClimbingStairs(const vector<int> &cost) {
    int a = cost[0], b = cost[1], c = 0;
    for (int i = 2; i < cost.size(); ++i) {
      c = cost[i] + min(a, b);
      a = b;
      b = c;
    }
    return min(a, b);
  }
};

int main() { return 0; }
