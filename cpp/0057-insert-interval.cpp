#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

bool comp(const vector<int> &a, const vector<int> &b) { return a[1] < b[0]; };

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    auto it =
        lower_bound(intervals.begin(), intervals.end(), newInterval, comp);
    auto jt =
        upper_bound(intervals.begin(), intervals.end(), newInterval, comp);

    if (jt == intervals.begin()) {
      intervals.insert(intervals.begin(), newInterval);
    } else if (it == intervals.end()) {
      intervals.push_back(newInterval);
    } else {
      newInterval[0] = min(newInterval[0], it->front());
      newInterval[1] = max(newInterval[1],
                           (jt == intervals.begin() ? it : prev(jt))->back());
      intervals.erase(it, jt);
      intervals.insert(it, newInterval);
    }
    return intervals;
  }
};

int main() {
  vector<vector<int>> intervals{{1, 5}};
  vector<int> newInterval{0, 0};
  vector<vector<int>> ans{{0, 0}, {1, 5}};
  Solution solution;
  solution.insert(intervals, newInterval);
  assert(intervals == ans);
  return 0;
}
