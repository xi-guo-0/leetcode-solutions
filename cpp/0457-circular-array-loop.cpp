#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool circularArrayLoop(vector<int> &nums) {
    auto step = [&](int x) {
      return (x + nums[x] + nums.size()) % nums.size();
    };

    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0)
        continue;
      int slow = i, fast = step(i);

      while (nums[i] * nums[fast] > 0 && nums[i] * nums[step(fast)] > 0) {
        if (slow == fast) {
          if (slow == step(slow))
            break;
          return true;
        }
        slow = step(slow);
        fast = step(step(fast));
      }
      int start = i, cur = i;
      while (nums[start] * nums[cur] > 0) {
        int next = step(cur);
        nums[cur] = 0;
        cur = next;
      }
    }
    return false;
  }
};

int main() {
  Solution solution;
  vector<int> nums{2, -1, 1, 2, 2};
  solution.circularArrayLoop(nums);
  return 0;
}
