#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> smallestRange(vector<vector<int>> &nums) {
    vector<pair<int, int>> merged;
    for (int i = 0; i < nums.size(); ++i)
      for (int num : nums[i])
        merged.push_back({num, i});
    sort(merged.begin(), merged.end());

    vector<int> ans = {-100000, 100000};
    vector<int> hash(nums.size(), 1);
    for (int i = 0, j = 0, c = 0; i < merged.size(); ++i) {
      if (hash[merged[i].second] == 1)
        ++c;
      hash[merged[i].second] -= 1;
      while (hash[merged[j].second] < 0) {
        hash[merged[j].second] += 1;
        ++j;
      }
      if (c == hash.size()) {
        if (merged[i].first - merged[j].first < ans[1] - ans[0]) {
          ans[1] = merged[i].first;
          ans[0] = merged[j].first;
        }
      }
    }

    return ans;
  }
};
