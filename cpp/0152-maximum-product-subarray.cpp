class Solution {
public:
  int maxProduct(const vector<int> &nums) {
    if (nums.empty())
      return 0;
    else if (nums.size() == 1)
      return nums.front();
    int ans = 0, neg = 0, pos = 0;
    for (const auto &n : nums) {
      if (0 < n) {
        pos = (pos == 0) ? n : pos * n;
        neg *= n;
      } else if (n < 0) {
        const int tmp = neg;
        neg = min(n, pos * n);
        pos = tmp * n;
      } else {
        pos = neg = 0;
      }
      ans = max(ans, pos);
    }
    return ans;
  }
};
