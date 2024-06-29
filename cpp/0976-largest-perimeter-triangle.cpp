#include <vector>

using namespace std;

class Solution {
public:
  int largestPerimeter(vector<int> &nums) {
    if (nums.size() < 3) {
      return 0;
    }
    int result = 0;
    sort(nums.rbegin(), nums.rend());
    int i = 0;
    while (i + 2 < nums.size() && nums[i] >= nums[i + 1] + nums[i + 2])
      i++;
    return (i + 2 < nums.size() && nums[i] < nums[i + 1] + nums[i + 2])
               ? nums[i] + nums[i + 1] + nums[i + 2]
               : 0;
  }
};

int main() { return 0; }
