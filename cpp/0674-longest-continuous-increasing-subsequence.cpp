#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    if (nums.size() < 1) {
      return 0;
    } else if (nums.size() < 2) {
      return 1;
    }

    int result = 0;
    int tmp = 1;

    for (size_t i = 1; i < nums.size(); ++i) {
      tmp = nums[i - 1] < nums[i] ? tmp + 1 : 1;
      result = std::max(result, tmp);
    }

    return result;
  }
};
