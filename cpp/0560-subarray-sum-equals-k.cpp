class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int ans = 0, sum = 0;
    unordered_map<int, int> dict;
    dict.emplace(0, 1);
    for (int num : nums) {
      sum += num;
      ans += dict[sum - k];
      ++dict[sum];
    }
    return ans;
  }
};
