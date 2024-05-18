class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    if (nums.size() == 0) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }
    int n = nums[0];
    auto p = stable_partition(nums.begin(), nums.end(),
                              [&n](int a) { return a > n; });
    while (distance(nums.begin(), p) != k - 1) {
      if (distance(nums.begin(), p) < k - 1) {
        n = *(p + 1);
        p = stable_partition(p + 1, nums.end(), [&n](int a) { return a > n; });
      } else {
        n = nums[0];
        p = stable_partition(nums.begin(), p, [&n](int a) { return a > n; });
      }
    }

    return nums[k - 1];
  }
};
