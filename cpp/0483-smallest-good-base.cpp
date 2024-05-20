#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string smallestGoodBase(string n) {
    using T = uint64_t;
    T num = stoull(n);

    for (int m = log2(num) + 1; m >= 2; --m) {
      T l = 2, r = pow(num, 1.0 / (m - 1)) + 1;
      while (l < r) {
        T mid = l + (r - l) / 2;

        T sum = 1, cur = 1;
        for (int i = 1; i < m; ++i) {
          cur *= mid;
          sum += cur;
        }

        if (sum == num) {
          return to_string(mid);
        } else if (sum < num) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
    }

    return to_string(num - 1);
  }
};
