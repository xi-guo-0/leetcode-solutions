#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  bool xorGame(const vector<int> &nums) {
    return nums.size() % 2 == 0 ||
           accumulate(nums.begin(), nums.end(), 0, bit_xor<int>()) == 0;
  }
};

int main() { return 0; }
