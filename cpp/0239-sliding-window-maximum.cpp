class monotonic_queue {
private:
  deque<int> data;

public:
  void push(const int n) {
    while (!data.empty() && data.back() < n)
      data.pop_back();
    data.push_back(n);
  }

  int max() { return data.front(); }

  void pop(const int n) {
    if (!data.empty() && data.front() == n)
      data.pop_front();
  }
};

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    monotonic_queue window;
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
      if (i < k - 1) {
        window.push(nums[i]);
      } else {
        window.push(nums[i]);
        ans.push_back(window.max());
        window.pop(nums[i - k + 1]);
      }
    }
    return ans;
  }
};
