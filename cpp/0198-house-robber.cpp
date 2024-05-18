class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    } else if (nums.size() == 1) {
      return nums[0];
    }
    int a = nums[0];
    int b = max(a, nums[1]);
    int t = 0;
    for (int i = 2; i < nums.size(); i++) {
      t = max(a + nums[i], b);
      a = b;
      b = t;
    }
    return b;
  }
};
