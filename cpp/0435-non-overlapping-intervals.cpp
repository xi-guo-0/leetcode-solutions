#include <algorithm>
#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    if (intervals.empty()) {
      return 0;
    }

    ranges::sort(intervals, [](const vector<int> &a, const vector<int> &b) {
      return (a[1] != b[1]) ? (a[1] < b[1]) : (a[0] > b[0]);
    });

    int end = intervals[0][1];
    int count = 1;
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] >= end) {
        end = intervals[i][1];
        count++;
      }
    }

    return intervals.size() - count;
  }
};

int main() { return 0; }
