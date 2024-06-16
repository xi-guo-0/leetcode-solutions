#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArrayByParity(vector<int> &nums) {
    vector<int> ans;
    vector<int> odd;
    for (const auto &n : nums)
      n & 0x1 ? odd.push_back(n) : ans.push_back(n);
    for (const auto &n : odd)
      ans.push_back(n);
    return ans;
  }
};

int main() { return 0; }
