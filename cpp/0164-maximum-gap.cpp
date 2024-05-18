class Solution {
public:
  int maximumGap(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    adjacent_find(nums.begin(), nums.end(),
                  [&ans](int const lhs, int const rhs) {
                    ans = max(ans, rhs - lhs);
                    return false;
                  });
    return ans;
  }
};
