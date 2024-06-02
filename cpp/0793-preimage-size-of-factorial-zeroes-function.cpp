#include <iostream>

class Solution {
public:
  int preimageSizeFZF(int k) {
    auto zeta = [](long long x) -> int {
      int count = 0;
      while (x > 0) {
        x /= 5;
        count += x;
      }
      return count;
    };

    auto findLeftBoundary = [&](int k) -> long long {
      long long left = 0, right = 5LL * (k + 1);
      while (left < right) {
        long long mid = left + (right - left) / 2;
        if (zeta(mid) < k) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
      return left;
    };

    auto findRightBoundary = [&](int k) -> long long {
      long long left = 0, right = 5LL * (k + 1);
      while (left < right) {
        long long mid = left + (right - left) / 2;
        if (zeta(mid) <= k) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
      return left;
    };

    long long left = findLeftBoundary(k);
    long long right = findRightBoundary(k);

    return right - left;
  }
};

int main() { return 0; }
