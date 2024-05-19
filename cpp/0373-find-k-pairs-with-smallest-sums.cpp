#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {

    vector<vector<int>> result;

    auto cmp = [&nums1, &nums2](const pair<int, int> &a,
                                const pair<int, int> &b) {
      return nums1[a.first] + nums2[a.second] >
             nums1[b.first] + nums2[b.second];
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
        cmp);

    for (int i = 0; i < nums1.size() && i < k; ++i) {
      pq.emplace(i, 0);
    }

    while (k-- > 0 && !pq.empty()) {
      auto idx_pair = pq.top();
      pq.pop();
      int i = idx_pair.first;
      int j = idx_pair.second;

      result.push_back({nums1[i], nums2[j]});

      if (j + 1 < nums2.size()) {
        pq.emplace(i, j + 1);
      }
    }

    return result;
  }
};
