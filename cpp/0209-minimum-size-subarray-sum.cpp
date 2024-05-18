class Solution {
public:
  int minSubArrayLen(const int s, const vector<int> &nums) {
    int res = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      while (s <= sum) {
        res = min(res, i + 1 - left);
        sum -= nums[left++];
      }
    }
    return (res != INT_MAX) ? res : 0;
  }
};
