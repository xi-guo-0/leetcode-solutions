#include <cmath>
#include <iostream>

class Solution {
public:
  int findKthNumber(int n, int k) {
    int i = 1;
    int p = 1;
    while (p < k) {
      int cnt = getCount(i, n);
      if (k < p + cnt) {
        i *= 10;
        p += 1;
      } else {
        i += 1;
        p += cnt;
      }
    }
    return i;
  }

private:
  static int getCount(long prefix, long n) {
    int cnt = 0;
    for (long a = prefix, b = prefix + 1; a <= n; a *= 10, b *= 10) {
      cnt += static_cast<int>(std::min(n + 1, b) - a);
    }
    return cnt;
  }
};
