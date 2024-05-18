class Solution {
public:
  int jump(vector<int> &nums) {
    int steps = 0, end = 0, max_pos = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      max_pos = max(max_pos, nums[i] + i);
      if (i == end) {
        end = max_pos;
        ++steps;
      }
    }
    return steps;
  }
};
