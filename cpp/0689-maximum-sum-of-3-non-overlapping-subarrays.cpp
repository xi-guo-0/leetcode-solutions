#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> sum(n + 1, 0);
    vector<int> left(n, 0);
    vector<int> right(n, n - k);
    vector<int> result(3, 0);

    for (int i = 0; i < n; ++i) {
      sum[i + 1] = sum[i] + nums[i];
    }

    int total = sum[k] - sum[0];
    for (int i = k; i < n; ++i) {
      if (sum[i + 1] - sum[i + 1 - k] > total) {
        left[i] = i + 1 - k;
        total = sum[i + 1] - sum[i + 1 - k];
      } else {
        left[i] = left[i - 1];
      }
    }

    total = sum[n] - sum[n - k];
    for (int i = n - k - 1; i >= 0; --i) {
      if (sum[i + k] - sum[i] >= total) {
        right[i] = i;
        total = sum[i + k] - sum[i];
      } else {
        right[i] = right[i + 1];
      }
    }

    int maxSum = 0;
    for (int i = k; i <= n - 2 * k; ++i) {
      int l = left[i - 1], r = right[i + k];
      int sum3 =
          sum[i + k] - sum[i] + sum[r + k] - sum[r] + sum[l + k] - sum[l];
      if (sum3 > maxSum) {
        maxSum = sum3;
        result[0] = l;
        result[1] = i;
        result[2] = r;
      }
    }

    return result;
  }
};
