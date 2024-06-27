#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int maxWidthRamp(vector<int> &nums) {
    int n = nums.size();
    stack<int> s;
    int max_width = 0;

    for (int i = 0; i < n; ++i) {
      if (s.empty() || nums[s.top()] > nums[i]) {
        s.push(i);
      }
    }

    for (int j = n - 1; 0 <= j; --j) {
      while (!s.empty() && nums[s.top()] <= nums[j]) {
        int idx = s.top();
        s.pop();
        max_width = max(max_width, j - idx);
      }
    }
    return max_width;
  }
};

int main() { return 0; }
