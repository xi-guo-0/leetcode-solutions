class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    k %= nums.size();
    reverse(nums.rbegin(), next(nums.rbegin(), k));
    reverse(next(nums.rbegin(), k), nums.rend());
    reverse(nums.begin(), nums.end());
  }
};
