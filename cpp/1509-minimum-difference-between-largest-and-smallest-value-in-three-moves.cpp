#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  int minDifference(vector<int> &nums) {
    if (nums.size() < 5) {
      return 0;
    }
    ranges::sort(nums);
    int64_t ans =
        static_cast<int64_t>(nums.back()) - static_cast<int64_t>(nums.front());
    for (int i = 0; i < 4; ++i) {
      auto l = static_cast<int64_t>(nums[i]);
      auto r = static_cast<int64_t>(nums[i + nums.size() - 4]);
      ans = min(ans, r - l);
    }
    return static_cast<int>(ans);
  }
};

int main() { return 0; }
