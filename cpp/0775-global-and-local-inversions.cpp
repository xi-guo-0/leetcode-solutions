#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isIdealPermutation(vector<int> &nums) {
    int max_val = -1;
    int n = nums.size();

    for (int i = 0; i < n - 2; ++i) {
      max_val = max(max_val, nums[i]);
      if (max_val > nums[i + 2]) {
        return false;
      }
    }
    return true;
  }
};
