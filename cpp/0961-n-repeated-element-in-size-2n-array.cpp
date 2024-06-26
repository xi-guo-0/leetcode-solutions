#include <vector>

using namespace std;

class Solution {
public:
  int repeatedNTimes(vector<int> &nums) {
    if (nums[0] == nums[2])
      return nums[0];
    else if (nums[1] == nums[3])
      return nums[1];
    for (auto it = 1 + nums.cbegin(); it != nums.cend(); ++it) {
      if (*it == *(it - 1))
        return *it;
    }
    return nums[0];
  }
};

int main() { return 0; }
