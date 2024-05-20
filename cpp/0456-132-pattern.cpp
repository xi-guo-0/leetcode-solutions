class Solution {
public:
  bool find132pattern(const vector<int> &nums) {
    if (nums.size() < 3)
      return false;
    int second = numeric_limits<int>::min();
    stack<int> sk;
    sk.push(nums.back());
    for (int i = nums.size() - 2; 0 <= i; --i) {
      if (nums[i] < second) {
        return true;
      } else {
        while (!sk.empty() && sk.top() < nums[i]) {
          second = max(second, sk.top());
          sk.pop();
        }
        sk.push(nums[i]);
      }
    }
    return false;
  }
};
