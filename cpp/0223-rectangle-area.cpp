#include <algorithm>
using namespace std;

class Solution {
public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2) {
    auto area1 = (ax2 - ax1) * (ay2 - ay1);
    auto area2 = (bx2 - bx1) * (by2 - by1);

    auto left = std::max(ax1, bx1);
    auto right = std::min(ax2, bx2);
    auto down = std::max(ay1, by1);
    auto up = std::min(ay2, by2);

    auto areaOverlap = 0;
    if (left < right && down < up) {
      areaOverlap = (right - left) * (up - down);
    }

    return area1 + area2 - areaOverlap;
  }
};
