class Solution {
public:
  int lengthOfLIS(const vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    int n = nums.size();
    vector<int> dp(1, INT_MAX);
    for (const auto &i : nums) {
      auto it = lower_bound(dp.begin(), dp.end(), i);
      if (it == dp.end())
        dp.push_back(i);
      else
        *it = i;
    }
    return dp.size();
  }
};
