#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &nums) {
    int n = nums.size();
    int count = 0;
    vector<unordered_map<long long, int>> dp(n);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        long long diff = (long long)nums[i] - nums[j];
        int sum = 0;
        if (dp[j].count(diff))
          sum = dp[j][diff];
        count += sum;
        dp[i][diff] += sum + 1;
      }
    }

    return count;
  }
};

int main() {
  Solution solution;
  vector<int> nums{2, 4, 6, 8, 10};
  solution.numberOfArithmeticSlices(nums);
  return 0;
}
