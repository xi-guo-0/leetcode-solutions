#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findRightInterval(vector<vector<int>> &intervals) {

    map<int, int> startIndexes;

    for (int i = 0; i < intervals.size(); ++i) {
      startIndexes[intervals[i][0]] = i;
    }

    vector<int> result;

    for (auto &interval : intervals) {
      auto it = startIndexes.lower_bound(interval[1]);

      if (it != startIndexes.end()) {
        result.push_back(it->second);
      } else {
        result.push_back(-1);
      }
    }

    return result;
  }
};
