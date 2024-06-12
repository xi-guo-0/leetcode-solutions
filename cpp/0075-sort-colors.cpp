#include <algorithm>
#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    partition(partition(nums.begin(), nums.end(), [](int x) { return x == 0; }),
              nums.end(), [](int x) { return x == 1; });
  }
};

int main() { return 0; }
