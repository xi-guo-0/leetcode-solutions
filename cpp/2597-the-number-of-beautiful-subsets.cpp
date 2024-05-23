class Solution {
public:
  int beautifulSubsets(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    unordered_map<int, int> s;
    return solve(nums, 0, k, s);
  }

private:
  int solve(vector<int> &nums, int index, int k, unordered_map<int, int> &s) {
    if (index >= nums.size()) {
      return any_of(s.begin(), s.end(), [](auto &x) { return x.second > 0; });
    }

    int include = 0, notinclude = 0;
    if (!s[nums[index] - k]) {
      s[nums[index]]++;
      include = solve(nums, index + 1, k, s);
      s[nums[index]]--;
    }

    return include + solve(nums, index + 1, k, s);
  }
};
