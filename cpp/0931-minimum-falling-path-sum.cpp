#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &A) {
    int n = A.size();
    for (int i = n - 2; 0 <= i; i--) {
      for (int j = 0; j < n; j++) {
        int a = j > 0 ? A[i + 1][j - 1] : INT_MAX;
        int b = A[i + 1][j];
        int c = j + 1 < n ? A[i + 1][j + 1] : INT_MAX;
        A[i][j] += min(min(a, b), c);
      }
    }
    return accumulate(A[0].begin(), A[0].end(), INT_MAX,
                      [](int a, int b) { return min(a, b); });
  }
};

int main() { return 0; }
