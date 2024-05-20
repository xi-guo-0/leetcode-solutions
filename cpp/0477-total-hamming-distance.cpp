class Solution {
public:
  int totalHammingDistance(const vector<int> &nums) {
    if (nums.empty())
      return 0;
    int ans = 0, n = nums.size();
    vector<int> cnt(l, 0);
    for (auto num : nums) {
      int i = 0;
      while (num) {
        cnt[i] += (num & 0x1);
        num >>= 1;
        ++i;
      }
    }
    for (const auto &k : cnt) {
      ans += k * (n - k);
    }
    return ans;
  }

private:
  static constexpr int l = 8 * sizeof(int);
};
