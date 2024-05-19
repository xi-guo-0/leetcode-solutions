#include <vector>

using namespace std;

class Solution {
public:
  int wiggleMaxLength(vector<int> &nums) {
    if (nums.size() < 2) {
      return nums.size();
    } else {
      int down = 1;
      int up = 1;
      for (int i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] < nums[i]) {
          up = down + 1;
        } else if (nums[i] < nums[i - 1]) {
          down = up + 1;
        }
      }
      return std::max(up, down);
    }
  }
};
