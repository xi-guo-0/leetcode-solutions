#include <cassert>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string largestNumber(vector<int> &nums) {
    sort(nums.rbegin(), nums.rend(), [](int const a, int const b) {
      using T = unsigned long long;
      T na = 10;
      while (a / na)
        na *= 10;
      T nb = 10;
      while (b / nb)
        nb *= 10;
      T ab = static_cast<T>(a) * nb + b;
      T ba = static_cast<T>(b) * na + a;
      return ab < ba;
    });
    string ans;
    for (int n : nums) {
      ans = (ans == "0" ? to_string(n) : ans + to_string(n));
    }
    return ans;
  }
};

int main() {

  vector<int> nums{1000000000, 1000000000};
  string ans = "10000000001000000000";
  assert(Solution().largestNumber(nums) == ans);
  return 0;
}
