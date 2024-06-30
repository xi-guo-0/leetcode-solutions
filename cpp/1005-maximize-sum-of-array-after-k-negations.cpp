#include <vector>

using namespace std;

class Solution {
public:
  int largestSumAfterKNegations(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    auto it = lower_bound(nums.begin(), nums.end(), 0);
    int ans = 0;
    if (k <= it - nums.begin()) {
      int i = 0;
      for (; i < k; ++i) {
        ans -= nums[i];
      }
      for (; i < nums.size(); ++i) {
        ans += nums[i];
      }
    } else {
      k -= (it - nums.begin());
      for (auto itt = nums.begin(); itt != it; ++itt) {
        *itt = -*itt;
      }
      sort(nums.begin(), nums.end());
      k = k % 2;
      if (k) {
        nums[0] = -nums[0];
      }
      for (int n : nums) {
        ans += n;
      }
    }
    return ans;
  }
};

int main() { return 0; }
