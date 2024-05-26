#include <vector>

using namespace std;

class Solution {
public:
  int smallestDistancePair(vector<int> &nums, int k) {
    if (nums.empty())
      return 0;
    sort(nums.begin(), nums.end());
    int low = 0, high = nums.back() - nums.front();
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (guess(nums, mid) < k) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return high;
  }

private:
  int guess(const vector<int> &nums, int k) {
    int right = 0, ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      while (right + 1 < nums.size() && nums[right + 1] - nums[i] <= k)
        ++right;
      ans += right - i;
    }
    return ans;
  }
};

int main() { return 0; }
