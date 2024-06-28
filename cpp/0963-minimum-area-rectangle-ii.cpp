#include <cmath>
#include <iostream>
#include <limits>
#include <unordered_set>
#include <vector>

using namespace std;

struct Point {
  double x, y;
  Point(double _x, double _y) : x(_x), y(_y) {}

  bool operator==(const Point &other) const {
    return x == other.x && y == other.y;
  }
};

struct PointHash {
  size_t operator()(const Point &p) const {
    return hash<double>()(p.x) ^ (hash<double>()(p.y) << 1);
  }
};

class Solution {
public:
  double minAreaFreeRect(vector<vector<int>> &points) {
    int n = points.size();
    unordered_set<Point, PointHash> pointSet;

    for (auto &p : points) {
      pointSet.insert(Point(p[0], p[1]));
    }

    double minArea = numeric_limits<double>::max();

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        Point p1(points[i][0], points[i][1]);
        Point p2(points[j][0], points[j][1]);

        double dx = p2.x - p1.x;
        double dy = p2.y - p1.y;

        for (int k = 0; k < n; ++k) {
          if (k == i || k == j)
            continue;
          Point p3(points[k][0], points[k][1]);

          double dx2 = p3.x - p1.x;
          double dy2 = p3.y - p1.y;

          if (dx * dx2 + dy * dy2 == 0) {
            Point p4(p2.x + dx2, p2.y + dy2);

            if (pointSet.count(p4) > 0) {
              double area =
                  sqrt(dx * dx + dy * dy) * sqrt(dx2 * dx2 + dy2 * dy2);
              minArea = min(minArea, area);
            }
          }
        }
      }
    }

    return minArea == numeric_limits<double>::max() ? 0 : minArea;
  }
};

int main() { return 0; }
