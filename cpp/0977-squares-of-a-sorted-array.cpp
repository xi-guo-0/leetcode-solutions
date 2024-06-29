#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    auto ans = nums;
    int l = 0;
    int r = nums.size() - 1;
    for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
      int a = square(nums[l]);
      int b = square(nums[r]);
      if (a <= b) {
        *it = b;
        --r;
      } else {
        *it = a;
        ++l;
      }
    }
    return ans;
  }

  int square(int x) { return x * x; }
};

int main() { return 0; }
