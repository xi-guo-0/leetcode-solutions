#include <algorithm>
#include <cstdint>
#include <numeric>

using namespace std;

class Solution {
public:
  int nthMagicalNumber(int n, int a, int b) {
    int64_t mod = 1'000'000'007;
    int64_t lcm = (a * b) / gcd(a, b);

    int64_t low = 0;
    int64_t high = 1e18;
    while (low < high) {
      int64_t mid = low + (high - low) / 2;
      if (countMagicalNumbers(mid, a, b, lcm) < n) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }

    return low % mod;
  }

private:
  int64_t countMagicalNumbers(int64_t num, int a, int b, int64_t lcm) {
    return num / a + num / b - num / lcm;
  }
};

int main() { return 0; }
