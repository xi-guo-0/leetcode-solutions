#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
  int sumSubseqWidths(vector<int> &nums) {
    constexpr int MOD = 1e9 + 7;
    int n = nums.size();
    long long sum = 0;

    sort(nums.begin(), nums.end());

    vector<long long> pow2(n);
    pow2[0] = 1;
    for (int i = 1; i < n; ++i) {
      pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    for (int i = 0; i < n; ++i) {

      sum = (sum + nums[i] * (pow2[i] - pow2[n - 1 - i] + MOD)) % MOD;
    }

    return static_cast<int>(sum);
  }
};

int main() { return 0; }
