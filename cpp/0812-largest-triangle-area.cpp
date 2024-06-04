#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
  double largestTriangleArea(const vector<vector<int>> &points) {
    double maxArea = 0.0;

    for (size_t i = 0; i < points.size(); ++i) {
      for (size_t j = i + 1; j < points.size(); ++j) {
        for (size_t k = j + 1; k < points.size(); ++k) {
          double area = abs((points[i][1] - points[k][1]) *
                                (points[j][0] - points[k][0]) -
                            (points[j][1] - points[k][1]) *
                                (points[i][0] - points[k][0])) /
                        2.0;
          maxArea = max(maxArea, area);
        }
      }
    }

    return maxArea;
  }
};

int main() { return 0; }
