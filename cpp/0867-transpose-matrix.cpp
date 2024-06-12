#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> transpose(const vector<vector<int>> &A) {
    if (A.size() == 0 || A[0].size() == 0) {
      return A;
    }
    const int m = A.size();
    const int n = A[0].size();
    vector<vector<int>> result(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        result[j][i] = A[i][j];
    return result;
  }
};

int main() { return 0; }
