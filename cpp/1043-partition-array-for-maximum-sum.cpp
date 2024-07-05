#include <vector>

using namespace std;

class Solution {
public:
  int maxSumAfterPartitioning(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
      int value = arr[i];
      for (int j = 1; 0 <= i - j + 1 && j <= k; ++j) {
        value = max(value, arr[i - j + 1]);
        if (0 <= i - j) {
          dp[i] = max(dp[i], dp[i - j] + j * value);
        } else {
          dp[i] = max(dp[i], j * value);
        }
      }
    }
    return dp.back();
  }
};

int main() { return 0; }