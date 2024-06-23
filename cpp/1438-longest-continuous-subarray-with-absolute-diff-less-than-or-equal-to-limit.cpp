#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &nums, int limit) {
    multiset<int> window;
    int left = 0, right = 0;
    int max_length = 0;

    while (right < nums.size()) {
      window.insert(nums[right]);

      while (*window.rbegin() - *window.begin() > limit) {
        window.erase(window.find(nums[left]));
        left++;
      }

      max_length = max(max_length, right - left + 1);

      right++;
    }

    return max_length;
  }
};

int main() { return 0; }
