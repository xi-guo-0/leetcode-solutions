#include <cmath>

using namespace std;

class Solution {
public:
  int consecutiveNumbersSum(int n) {
    int ans = 1;
    int len = static_cast<int>(ceil(sqrt(2 * n)));
    for (int i = 2; i < len; ++i) {
      if ((n - i * (i - 1) / 2) % i == 0) {
        ++ans;
      }
    }
    return ans;
  }
};

int main() { return 0; }
