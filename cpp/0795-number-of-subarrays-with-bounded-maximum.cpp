#include <vector>

using namespace std;

class Solution {
public:
  int numSubarrayBoundedMax(vector<int> const &A, int L, int R) {
    return count(A, R) - count(A, L - 1);
  }

private:
  int count(vector<int> const &A, int const bound) {
    int ans = 0, cur = 0;
    for (int x : A) {
      cur = x <= bound ? cur + 1 : 0;
      ans += cur;
    }
    return ans;
  }
};

int main() { return 0; }
