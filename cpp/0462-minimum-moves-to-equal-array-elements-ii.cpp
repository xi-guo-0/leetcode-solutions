class Solution {
public:
  int minMoves2(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int result = 0;
    for (int i = 0, j = nums.size() - 1; i < j; i++, j--)
      result += nums[j] - nums[i];
    return result;
  }
};
