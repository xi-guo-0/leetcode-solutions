#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
  int smallestRangeII(vector<int> &nums, int k) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int minRange = nums[n - 1] - nums[0];

    for (int i = 0; i < n - 1; ++i) {
      int currentMax = max(nums[i] + k, nums[n - 1] - k);
      int currentMin = min(nums[0] + k, nums[i + 1] - k);
      int currentRange = currentMax - currentMin;

      minRange = min(minRange, currentRange);
    }

    return minRange;
  }
};

int main() { return 0; }
