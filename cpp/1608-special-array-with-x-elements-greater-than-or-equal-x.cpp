#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int specialArray(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    if (nums.size() <= nums[0]) {
      return nums.size();
    }
    for (int i = 1; i < nums.size(); ++i) {
      int special = nums.size() - i;
      if (nums[i - 1] < special && special <= nums[i]) {
        return special;
      }
    }
    return -1;
  }
};

int main() { return 0; }
