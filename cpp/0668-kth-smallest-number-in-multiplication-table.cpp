#include <iostream>
#include <vector>

using namespace std;

int countLessEqual(int m, int n, int mid) {
  int count = 0;
  for (int i = 1; i <= m; ++i) {
    count += min(mid / i, n);
  }
  return count;
}

class Solution {
public:
  int findKthNumber(int m, int n, int k) {
    int low = 1, high = m * n;
    while (low < high) {
      int mid = low + (high - low) / 2;
      int count = countLessEqual(m, n, mid);
      if (count < k) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};
