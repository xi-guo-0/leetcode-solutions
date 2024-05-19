#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxRotateFunction(vector<int> &nums) {
    int n = nums.size();
    long long sum = 0;
    long long F = 0;

    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      F += i * nums[i];
    }

    long long maxF = F;

    for (int i = 1; i < n; ++i) {
      F = F + sum - n * nums[n - i];
      maxF = max(maxF, F);
    }

    return maxF;
  }
};
