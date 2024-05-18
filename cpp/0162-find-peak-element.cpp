class Solution {
public:
  int findPeakElement(const vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m + 1] < nums[m])
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
