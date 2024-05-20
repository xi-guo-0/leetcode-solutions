#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int maximum = 0;
    bool isOne = false;
    int count = 0;
    for (int num : nums) {
      if (isOne) {
        if (1 == num) {
          count += 1;
        } else {
          isOne = false;
          maximum = max(count, maximum);
        }
      } else {
        if (1 == num) {
          isOne = true;
          count = 1;
        }
      }
    }
    maximum = max(count, maximum);
    return maximum;
  }
};
