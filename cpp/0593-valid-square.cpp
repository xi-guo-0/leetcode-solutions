#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct Point {
  int x, y;
  Point(int _x, int _y) : x(_x), y(_y) {}
  bool operator==(const Point &other) const {
    return x == other.x && y == other.y;
  }
};

namespace std {
template <> struct hash<Point> {
  size_t operator()(const Point &p) const {
    return hash<int>()(p.x) ^ hash<int>()(p.y);
  }
};
} // namespace std

int squaredDistance(const Point &p1, const Point &p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

class Solution {
public:
  bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3,
                   vector<int> &p4) {
    unordered_set<int> d;
    vector<Point> v = {Point(p1[0], p1[1]), Point(p2[0], p2[1]),
                       Point(p3[0], p3[1]), Point(p4[0], p4[1])};
    for (int i = 0; i < 4; ++i) {
      for (int j = i + 1; j < 4; ++j) {
        d.insert(squaredDistance(v[i], v[j]));
      }
    }
    auto minD = *min_element(d.begin(), d.end());
    auto maxD = *max_element(d.begin(), d.end());
    return d.size() == 2 && minD != 0 && minD * 2 == maxD;
  }
};
