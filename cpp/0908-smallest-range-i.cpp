#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int smallestRangeI(vector<int> &nums, int k) {
    if (nums.size() == 0) {
      return 0;
    }
    int low = nums[0];
    int high = nums[0];
    for (auto n : nums) {
      low = min(low, n);
      high = max(high, n);
    }
    return max(0, high - low - 2 * k);
  }
};

int main() { return 0; }
