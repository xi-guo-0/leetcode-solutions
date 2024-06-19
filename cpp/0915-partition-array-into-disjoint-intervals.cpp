#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  int partitionDisjoint(vector<int> &A) {
    int n = A.size();
    vector<int> rightLeast(n);
    rightLeast[n - 1] = numeric_limits<int>::max();

    for (int i = n - 2; i >= 0; --i) {
      rightLeast[i] = min(A[i + 1], rightLeast[i + 1]);
    }

    int l = 0;
    int lm = A[0];

    while (rightLeast[l] < lm) {
      ++l;
      lm = max(lm, A[l]);
    }

    return l + 1;
  }
};

int main() { return 0; }
