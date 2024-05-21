#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int removeBoxes(vector<int> &boxes) {
    if (boxes.empty())
      return 0;
    int n = boxes.size();
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(n, vector<int>(n, 0)));
    return helper(boxes, 0, n - 1, 0, dp);
  }

  int helper(vector<int> &boxes, int lo, int hi, int carry,
             vector<vector<vector<int>>> &dp) {
    if (lo > hi)
      return 0;
    if (dp[lo][hi][carry] > 0)
      return dp[lo][hi][carry];
    int origLo = lo, origCarry = carry;
    while (lo + 1 <= hi && boxes[lo + 1] == boxes[lo])
      lo++;
    carry += lo - origLo + 1;
    int res = carry * carry + helper(boxes, lo + 1, hi, 0, dp);
    for (int i = lo + 2; i <= hi; i++) {
      if (boxes[i] == boxes[origLo]) {
        res = max(res, helper(boxes, lo + 1, i - 1, 0, dp) +
                           helper(boxes, i, hi, carry, dp));
      }
    }
    dp[origLo][hi][origCarry] = res;
    return res;
  }
};
