#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int countRangeSum(vector<int> &nums, int lower, int upper) {
    int n = nums.size();
    vector<long> sums(n + 1);
    for (int i = 0; i < n; ++i) {
      sums[i + 1] = sums[i] + nums[i];
    }
    return mergeCount(sums, lower, upper, 0, n);
  }

  int mergeCount(vector<long> &sums, int lower, int upper, int left,
                 int right) {
    if (left >= right)
      return 0;
    int mid = left + (right - left) / 2;
    int count = mergeCount(sums, lower, upper, left, mid) +
                mergeCount(sums, lower, upper, mid + 1, right);
    int j = mid + 1, k = mid + 1;
    for (int i = left; i <= mid; ++i) {
      while (j <= right && sums[j] - sums[i] < lower)
        ++j;
      while (k <= right && sums[k] - sums[i] <= upper)
        ++k;
      count += k - j;
    }
    inplace_merge(sums.begin() + left, sums.begin() + mid + 1,
                  sums.begin() + right + 1);
    return count;
  }
};
