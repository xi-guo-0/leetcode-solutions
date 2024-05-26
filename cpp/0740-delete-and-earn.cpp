#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int deleteAndEarn(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }

    int max_num = *max_element(nums.begin(), nums.end());

    vector<int> points(max_num + 1, 0);
    for (int num : nums) {
      points[num] += num;
    }

    vector<int> dp(max_num + 1, 0);
    dp[1] = points[1];

    for (int i = 2; i <= max_num; ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + points[i]);
    }

    return dp[max_num];
  }
};

int main() { return 0; }
