class Solution {
public:
  bool canJump(vector<int> &nums) {
    int lastPos = nums.size() - 1;
    for (int i = lastPos; 0 <= i; --i) {
      if (lastPos <= i + nums[i]) {
        lastPos = i;
      }
    }
    return lastPos == 0;
  }
};
