#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findIntegers(int n) {
    vector<int> dp(32);
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < dp.size(); ++i) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    int res = 0, pre_bit = 0;
    bool consecutive = false;

    for (int i = 30; i >= 0; --i) {
      if ((n & (1 << i)) != 0) {
        res += dp[i];
        if (pre_bit == 1) {
          consecutive = true;
          break;
        }
        pre_bit = 1;
      } else {
        pre_bit = 0;
      }
    }

    return res + !consecutive;
  }
};
