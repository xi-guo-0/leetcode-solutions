#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;

    vector<int> lengths(n, 1);
    vector<int> counts(n, 1);

    int maxLength = 1;

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          if (lengths[j] + 1 > lengths[i]) {
            lengths[i] = lengths[j] + 1;
            counts[i] = counts[j];
          } else if (lengths[j] + 1 == lengths[i]) {
            counts[i] += counts[j];
          }
        }
      }
      maxLength = max(maxLength, lengths[i]);
    }

    int numberOfLIS = 0;
    for (int i = 0; i < n; ++i) {
      if (lengths[i] == maxLength) {
        numberOfLIS += counts[i];
      }
    }

    return numberOfLIS;
  }
};
