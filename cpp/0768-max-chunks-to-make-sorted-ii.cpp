#include <vector>

using namespace std;

class Solution {
public:
  int maxChunksToSorted(const vector<int> &arr) {
    if (arr.empty())
      return 0;
    const int n = arr.size();
    vector<int> lmax(n, numeric_limits<int>::max());
    vector<int> rmin(n, numeric_limits<int>::min());
    lmax.front() = arr.front();
    rmin.back() = arr.back();
    for (int i = 1; i < n; ++i) {
      lmax[i] = max(lmax[i - 1], arr[i]);
      rmin[n - 1 - i] = min(rmin[n - i], arr[n - 1 - i]);
    }
    int ans = 1;
    for (int i = 0; i + 1 < n; ++i)
      ans += lmax[i] <= rmin[i + 1];
    return ans;
  }
};

int main() { return 0; }
