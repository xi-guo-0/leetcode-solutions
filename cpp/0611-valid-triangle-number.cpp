class Solution {
public:
  int triangleNumber(vector<int> &nums) {
    sort(begin(nums), end(nums));
    int ans = 0;
    for (auto f = begin(nums); f != end(nums); ++f) {
      for (auto s = f + 1; s != end(nums); ++s) {
        auto t = lower_bound(s + 1, end(nums), (*f) + (*s));
        ans += distance(s + 1, t);
      }
    }
    return ans;
  }
};
