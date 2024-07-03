#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < m; ++i) {
      for (int j = n - 1; 0 <= j; --j) {
        if (nums1[i] == nums2[j]) {
          dp[j + 1] = dp[j] + 1;
        }
      }
      for (int j = 0; j < n; ++j) {
        dp[j + 1] = max(dp[j + 1], dp[j]);
      }
    }
    return dp[n];
  }
};

int main() { return 0; }
