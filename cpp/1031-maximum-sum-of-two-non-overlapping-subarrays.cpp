#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
    int n = nums.size();
    vector<int> prefix(n + 1);

    for (int i = 1; i <= n; ++i) {
      prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    int maxSum = 0;

    for (int i = 0; i <= n - firstLen; ++i) {

      int sumL = prefix[i + firstLen] - prefix[i];

      for (int j = 0; j <= n - secondLen; ++j) {
        if (j + secondLen <= i || j >= i + firstLen) {

          int sumM = prefix[j + secondLen] - prefix[j];

          maxSum = max(maxSum, sumL + sumM);
        }
      }
    }

    return maxSum;
  }
};

int main() { return 0; }
