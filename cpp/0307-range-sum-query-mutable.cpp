class NumArray {
public:
  NumArray(vector<int> &nums) : nums(nums) {
    sums = vector<long long>(1 + nums.size(), 0);
    for (int i = 1; i < sums.size(); i++)
      sums[i] = sums[i - 1] + static_cast<long long>(nums[i - 1]);
  }

  void update(int index, int val) {
    int dx = val - nums[index];
    nums[index] = val;
    for (++index; index < sums.size(); ++index)
      sums[index] += dx;
  }

  int sumRange(int left, int right) {
    return static_cast<int>(sums[right + 1] - sums[left]);
  }

private:
  vector<int> &nums;
  vector<long long> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
