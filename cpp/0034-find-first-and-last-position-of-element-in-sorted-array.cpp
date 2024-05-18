#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> searchRange(const vector<int> &nums, const int target) {
    if (nums.empty() || target < nums.front() || nums.back() < target ||
        !binary_search(nums.begin(), nums.end(), target)) {
      return {-1, -1};
    }
    return {static_cast<int>(lower_bound(nums.begin(), nums.end(), target) -
                             nums.begin()),
            static_cast<int>(upper_bound(nums.begin(), nums.end(), target) -
                             nums.begin() - 1)};
  }
};
