#include <algorithm>
#include <limits>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int minAreaRect(vector<vector<int>> &points) {
    unordered_set<int> pointSet;
    int minArea = numeric_limits<int>::max();

    for (const auto &point : points) {
      int x = point[0];
      int y = point[1];
      pointSet.insert(x * 40001 + y);
    }

    int n = points.size();
    for (int i = 0; i < n; ++i) {
      int x1 = points[i][0];
      int y1 = points[i][1];
      for (int j = i + 1; j < n; ++j) {
        int x2 = points[j][0];
        int y2 = points[j][1];

        if (x1 != x2 && y1 != y2) {
          if (pointSet.count(x1 * 40001 + y2) &&
              pointSet.count(x2 * 40001 + y1)) {
            int area = abs(x1 - x2) * abs(y1 - y2);
            minArea = min(minArea, area);
          }
        }
      }
    }

    return minArea == numeric_limits<int>::max() ? 0 : minArea;
  }
};

int main() { return 0; }
