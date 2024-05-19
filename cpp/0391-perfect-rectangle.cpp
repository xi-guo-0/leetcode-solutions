#include <cstdint>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct Point {
  int x, y;

  bool operator==(const Point &other) const {
    return x == other.x && y == other.y;
  }
};

struct HashPoint {
  size_t operator()(const Point &p) const {
    return hash<int>()(p.x) ^ hash<int>()(p.y);
  }
};

class Solution {
public:
  bool isRectangleCover(vector<vector<int>> &rectangles) {
    unordered_set<Point, HashPoint> corners;
    int64_t area = 0;

    for (const auto &rect : rectangles) {
      Point bottomLeft = {rect[0], rect[1]};
      Point bottomRight = {rect[2], rect[1]};
      Point topLeft = {rect[0], rect[3]};
      Point topRight = {rect[2], rect[3]};

      vector<Point> rectCorners = {bottomLeft, bottomRight, topLeft, topRight};

      for (const auto &corner : rectCorners) {
        if (corners.count(corner))
          corners.erase(corner);
        else
          corners.insert(corner);
      }

      area += static_cast<int64_t>(rect[2] - rect[0]) * (rect[3] - rect[1]);
    }

    if (corners.size() != 4)
      return false;

    Point bottomLeft = {INT_MAX, INT_MAX};
    Point topRight = {INT_MIN, INT_MIN};

    for (const auto &corner : corners) {
      bottomLeft.x = min(bottomLeft.x, corner.x);
      bottomLeft.y = min(bottomLeft.y, corner.y);
      topRight.x = max(topRight.x, corner.x);
      topRight.y = max(topRight.y, corner.y);
    }

    return area == static_cast<int64_t>(topRight.x - bottomLeft.x) *
                       (topRight.y - bottomLeft.y);
  }
};
