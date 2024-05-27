#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int dominantIndex(const vector<int> &nums) {
    if (nums.size() == 1)
      return 0;
    int f = 0, s = 1;
    if (nums[f] < nums[s])
      swap(f, s);
    for (int i = 2; i < nums.size(); i++) {
      if (nums[f] < nums[i]) {
        s = f;
        f = i;
      } else if (nums[s] < nums[i] && nums[i] < nums[f]) {
        s = i;
      }
    }
    return nums[s] * 2 <= nums[f] ? f : -1;
  }
};

int main() { return 0; }
