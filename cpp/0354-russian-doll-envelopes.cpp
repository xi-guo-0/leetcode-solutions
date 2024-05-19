#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    sort(envelopes.begin(), envelopes.end(),
         [](const vector<int> &a, const vector<int> &b) {
           return a[0] != b[0] ? a[0] < b[0] : b[1] < a[1];
         });

    vector<int> a(envelopes.size());
    for (int i = 0; i < a.size(); ++i) {
      a[i] = envelopes[i][1];
    }

    return lengthOfLIS(a);
  }

private:
  int lengthOfLIS(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    } else {
      vector<int> dp;
      dp.push_back(INT_MAX);
      for (int x : nums) {
        int i = lowerBound(dp, 0, dp.size(), x);
        if (i == dp.size()) {
          dp.push_back(x);
        } else {
          dp[i] = x;
        }
      }
      return dp.size();
    }
  }

  static int lowerBound(vector<int> &a, int lo, int hi, int key) {
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (a[mid] < key) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    return lo;
  }
};
