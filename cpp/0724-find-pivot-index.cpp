#include <vector>

using namespace std;

class Solution {
public:
  int pivotIndex(const vector<int> &nums) {
    if (nums.size() == 0) {
      return -1;
    } else if (nums.size() == 1) {
      return 0;
    }
    int n = nums.size();
    int sum = 0;
    vector<int> r(n, nums[n - 1]);
    for (int i = n - 2; 0 <= i; i--)
      r[i] = r[i + 1] + nums[i];
    for (int i = 0; i < n; i++)
      if ((sum += nums[i]) == r[i])
        return i;
    return -1;
  }
};

int main() { return 0; }
