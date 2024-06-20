#include <vector>

using namespace std;

class Solution {
public:
  int threeSumMulti(vector<int> &arr, const int target) {

    constexpr long M = 1000'000'007;
    sort(arr.begin(), arr.end());
    long ans = 0;
    for (int i = 0; i + 2 < arr.size(); ++i) {
      const int t = target - arr[i];
      if (t < 2 * arr[i])
        break;
      int l = i + 1, r = arr.size() - 1;
      while (arr[l] < arr[r]) {
        if (t < arr[l] + arr[r]) {
          --r;
        } else if (arr[l] + arr[r] < t) {
          ++l;
        } else {
          const int tl = l;
          const int tr = r;
          while (arr[++l] == arr[tl])
            ;
          while (arr[--r] == arr[tr])
            ;
          ans += (l - tl) * (tr - r);
          ans %= M;
        }
      }
      if (arr[l] == arr[r] && arr[l] + arr[r] == t) {
        const int d = r - l + 1;
        ans += d * (d - 1) / 2;
        ans %= M;
      }
    }
    return ans;
  }
};

int main() { return 0; }
