#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int left = 0, right = 0;
    int maxLength = 0;
    int zerosCount = 0;

    while (right < nums.size()) {

      if (nums[right] == 0) {
        zerosCount++;
      }

      while (zerosCount > k) {
        if (nums[left] == 0) {
          zerosCount--;
        }
        left++;
      }

      maxLength = max(maxLength, right - left + 1);
      right++;
    }

    return maxLength;
  }
};

int main() { return 0; }
