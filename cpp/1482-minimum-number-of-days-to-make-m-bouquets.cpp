#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

class Solution {
public:
  int minDays(vector<int> &bloomDay, int m, int k) {
    int ans = -1;
    if (bloomDay.size() < static_cast<int64_t>(m) * static_cast<int64_t>(k)) {
      ans = -1;
    } else {
      int l = bloomDay[0];
      int r = bloomDay[0];
      for (int x : bloomDay) {
        l = min(l, x);
        r = max(r, x);
      }
      if (bloomDay.size() ==
          static_cast<int64_t>(m) * static_cast<int64_t>(k)) {
        ans = r;
      } else {
        while (l <= r) {
          int mid = l + (r - l) / 2;
          if (satisfy(bloomDay, m, k, mid)) {
            ans = mid;
            r = mid - 1;
          } else {
            l = mid + 1;
          }
        }
      }
    }
    return ans;
  }

private:
  static bool satisfy(const vector<int> &bloomDay, int m, int k, int v) {
    int cnt = 0;
    int len = 0;
    for (int x : bloomDay) {
      if (x <= v) {
        ++len;
        if (len == k) {
          ++cnt;
          len = 0;
        }
      } else {
        len = 0;
      }
    }
    return m <= cnt;
  }
};

int main() { return 0; }
