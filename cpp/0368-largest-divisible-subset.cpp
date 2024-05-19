#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    if (nums.empty())
      return {};

    sort(nums.begin(), nums.end());

    vector<int> dp(nums.size(), 1);
    vector<int> prev(nums.size(), -1);

    int maxIndex = 0;

    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          prev[i] = j;
        }
      }
      if (dp[i] > dp[maxIndex]) {
        maxIndex = i;
      }
    }

    vector<int> result;
    while (maxIndex != -1) {
      result.push_back(nums[maxIndex]);
      maxIndex = prev[maxIndex];
    }

    return result;
  }
};

int main() { return 0; }
