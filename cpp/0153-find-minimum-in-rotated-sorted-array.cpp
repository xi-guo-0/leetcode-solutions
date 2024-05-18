class Solution {
public:
  int findMin(const vector<int> &nums) {
    if (nums.empty())
      return 0;
    auto l = nums.begin(), r = prev(nums.end());
    while (l != r) {
      const auto m = l + (r - l) / 2;
      if (*l <= *r)
        return *l;
      else if (*l <= *m)
        l = m + 1;
      else
        r = m;
    }
    return *l;
  }
};
