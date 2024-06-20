#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArrayByParityII(vector<int> &nums) {
    if (nums.size() < 2) {
      return nums;
    }
    int index = 1;
    while (index < nums.size() && nums[index] & 0x1)
      index += 2;
    for (int j = 0; j < nums.size(); j += 2)
      if (nums[j] & 0x1) {
        swap(nums[j], nums[index]);
        while (index < nums.size() && nums[index] & 0x1)
          index += 2;
      }
    return nums;
  }
};

int main() { return 0; }
