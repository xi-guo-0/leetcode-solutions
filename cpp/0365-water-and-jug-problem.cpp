class Solution {
public:
  bool canMeasureWater(int x, int y, int target) {
    if (target == 0) {
      return true;
    } else if (x + y < target) {
      return false;
    } else if (y < x) {
      return canMeasureWater(y, x, target);
    } else if (x == 0) {
      return y == target;
    } else {
      while (y % x != 0) {
        int r = y % x;
        y = x;
        x = r;
      }
      return target % x == 0;
    }
  }
};
