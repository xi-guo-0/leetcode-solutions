class Solution {
public:
  int minMoves(vector<int> &nums) {
    int min = nums[0];
    int sum = 0;
    for (int num : nums) {
      if (min > num) {
        min = num;
      }
      sum += num;
    }
    return sum - nums.size() * min;
  }
};
