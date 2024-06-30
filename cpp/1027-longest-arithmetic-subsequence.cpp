#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int longestArithSeqLength(vector<int> &nums) {
    if (nums.size() < 3) {
      return nums.size();
    }
    const int n = nums.size();
    vector<unordered_map<int, int>> dp(n);
    int result = 2;
    for (int j = 1; j < nums.size(); j++) {
      for (int i = 0; i < j; i++) {
        const int key = nums[j] - nums[i];
        if (dp[i].count(key))
          dp[j][key] = dp[i][key] + 1;
        else
          dp[j][key] = 2;
        result = max(result, dp[j][key]);
      }
    }
    return result;
  }
};

int main() { return 0; }
