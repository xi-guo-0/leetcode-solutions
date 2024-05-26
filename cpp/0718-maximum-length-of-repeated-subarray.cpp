#include <vector>

using namespace std;

class Solution {
public:
  int findLength(const vector<int> &A, const vector<int> &B) {
    const int m = A.size(), n = B.size();
    int res = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        if (A[i - 1] == B[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          res = max(res, dp[i][j]);
        }
    return res;
  }
};

int main() { return 0; }
