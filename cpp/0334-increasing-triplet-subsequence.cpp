class Solution {
public:
  bool increasingTriplet(const vector<int> &nums) {
    if (nums.size() < 3) {
      return false;
    }
    int n = nums.size();
    vector<int> dp(1, INT_MAX);
    for (const auto &i : nums) {
      auto it = lower_bound(dp.begin(), dp.end(), i);
      if (it == dp.end()) {
        if (dp.size() == 2)
          return true;
        dp.push_back(i);
      } else
        *it = i;
    }
    return false;
  }
};
