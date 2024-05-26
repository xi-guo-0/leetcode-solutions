#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    if (k <= 1)
      return 0;

    int start = 0;
    int product = 1;
    int count = 0;

    for (int end = 0; end < nums.size(); ++end) {
      product *= nums[end];
      while (product >= k && start <= end) {
        product /= nums[start++];
      }
      count += end - start + 1;
    }

    return count;
  }
};

int main() {
  Solution solution;
  vector<int> nums{10, 5, 2, 6};
  int k = 100;
  assert((solution.numSubarrayProductLessThanK(nums, k) == 8));
  return 0;
}
