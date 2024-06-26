#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    int64_t diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    diff &= -diff;
    vector<int> result(2, 0);
    for (auto i : nums) {
      if (i & diff)
        result[0] ^= i;
      else
        result[1] ^= i;
    }
    return result;
  }
};

int main() { return 0; }
