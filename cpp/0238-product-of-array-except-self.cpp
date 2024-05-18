class Solution {
public:
  vector<int> productExceptSelf(const vector<int> &nums) {
    if (nums.size() < 2) {
      return nums;
    }
    vector<int> result(nums.size(), 1);
    int k = 1;
    for (int i = 0; i < result.size(); i++) {
      result[i] = k;
      k *= nums[i];
    }
    k = 1;
    for (int j = result.size() - 1; 0 <= j; j--) {
      result[j] *= k;
      k *= nums[j];
    }
    return result;
  }
};
