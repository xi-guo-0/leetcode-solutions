#include <algorithm>
#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  int minIncrementForUnique(vector<int> &nums) {
    ranges::sort(nums);
    int ans = 0;
    int step = 0;
    for (auto n : nums) {
      ans += max(step, n) - n;
      step = max(step, n) + 1;
    }
    return ans;
  }
};

int main() { return 0; }
