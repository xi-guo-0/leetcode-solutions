class Solution {
public:
  double findMaxAverage(const vector<int> &nums, int k) {
    if (nums.size() < k) {
      return accumulate(nums.begin(), nums.end(), 0) / (double)k;
    }
    double sum = accumulate(nums.begin(), next(nums.begin(), k), 0);
    double result = sum;
    for (int i = k; i < nums.size(); i++) {
      sum = sum + nums[i] - nums[i - k];
      result = max(result, sum);
    }
    return result / k;
  }
};
