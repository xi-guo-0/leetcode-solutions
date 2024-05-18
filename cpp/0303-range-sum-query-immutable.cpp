class NumArray {
public:
  NumArray(const vector<int> &nums) {
    dp = vector<int>(1 + nums.size(), 0);
    for (int i = 0; i < nums.size(); i++)
      dp[i + 1] = dp[i] + nums[i];
  }

  int sumRange(int i, int j) { return dp[j + 1] - dp[i]; }

private:
  vector<int> dp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
