#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int minSwap(vector<int> &A, vector<int> &B) {
    int N = A.size();
    if (N < 2)
      return 0;
    int res_keep = 0;
    int res_swap = 1;
    for (int i = 1; i < N; ++i) {
      bool b1 = (A[i] > A[i - 1] && B[i] > B[i - 1]);
      bool b2 = (A[i] > B[i - 1] && B[i] > A[i - 1]);
      if (b1 && b2) {
        res_keep = min(res_keep, res_swap);
        res_swap = 1 + res_keep;
      } else if (b1) {
        res_swap = res_swap + 1;
      } else if (b2) {
        int t = res_swap;
        res_swap = res_keep + 1;
        res_keep = t;
      }
    }
    return min(res_swap, res_keep);
  }
};

int main() { return 0; }
