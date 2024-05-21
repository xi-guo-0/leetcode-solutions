#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int arrayPairSum(vector<int> &nums) {
    int sum = 0;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i += 2) {
      sum += nums[i];
    }
    return sum;
  }
};
