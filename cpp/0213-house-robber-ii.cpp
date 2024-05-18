class Solution {
public:
  int rob(const vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    } else if (nums.size() == 1) {
      return nums[0];
    } else if (nums.size() == 2) {
      return max(nums[0], nums[1]);
    }

    int n = nums.size();
    vector<int> dp0(n, 0);
    vector<int> dp1(n, 0);
    dp0[1] = nums[1];
    dp0[2] = max(nums[1], nums[2]);
    dp1[0] = nums[0];
    dp1[1] = max(nums[0], nums[1]);
    for (int i = 3; i < n; i++)
      dp0[i] = max(dp0[i - 1], nums[i] + dp0[i - 2]);
    for (int i = 2; i < n - 1; i++)
      dp1[i] = max(dp1[i - 1], nums[i] + dp1[i - 2]);
    return max(dp0[n - 1], dp1[n - 2]);
  }
};
