#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  bool canThreePartsEqualSum(vector<int> &A) {
    int sum = accumulate(A.begin(), A.end(), 0);
    if (sum % 3 != 0)
      return false;

    int target = sum / 3;
    return recursion(A, 0, A.size(), target, 1);
  }

private:
  bool recursion(const vector<int> &A, int left, int len, int target,
                 int depth) {
    if (left == len)
      return false;

    int sum = 0;
    for (int i = left; i < len; ++i) {
      sum += A[i];
      if (depth < 3 && sum == target) {
        return recursion(A, i + 1, len, target, depth + 1);
      }
    }

    return sum == target;
  }
};

int main() { return 0; }
