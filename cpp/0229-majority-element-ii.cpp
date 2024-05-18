#include <vector>

class Solution {
public:
  std::vector<int> majorityElement(const std::vector<int> &nums) {
    int c0 = 0;
    int c1 = 0;
    int n0 = 0;
    int n1 = 0;

    for (int x : nums) {
      if (c0 == x) {
        ++n0;
        continue;
      }
      if (c1 == x) {
        ++n1;
        continue;
      }
      if (n0 == 0) {
        n0 = 1;
        c0 = x;
        continue;
      }
      if (n1 == 0) {
        n1 = 1;
        c1 = x;
        continue;
      }
      --n0;
      --n1;
    }

    int cnt0 = 0;
    int cnt1 = 0;
    for (int x : nums) {
      if (c0 == x) {
        ++cnt0;
      } else if (c1 == x) {
        ++cnt1;
      }
    }

    std::vector<int> ans;
    if (nums.size() / 3 < cnt0) {
      ans.push_back(c0);
    }
    if (nums.size() / 3 < cnt1) {
      ans.push_back(c1);
    }
    return ans;
  }
};
