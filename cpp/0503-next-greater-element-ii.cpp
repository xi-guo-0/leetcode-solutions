class Solution {
public:
  vector<int> nextGreaterElements(const vector<int> &nums) {
    if (nums.empty())
      return vector<int>();
    const int n = nums.size();
    stack<int> s;
    vector<int> ans(nums);
    for (int i = 2 * n - 1; 0 <= i; --i) {
      while (!s.empty() && nums[s.top()] <= nums[i % n])
        s.pop();
      ans[i % n] = s.empty() ? -1 : nums[s.top()];
      s.push(i % n);
    }
    return ans;
  }
};
