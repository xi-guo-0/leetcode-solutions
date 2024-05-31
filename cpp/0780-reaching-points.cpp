#include <iostream>

using namespace std;

class Solution {
public:
  bool reachingPoints(int sx, int sy, int tx, int ty) {
    while (sx < tx && sy < ty) {
      if (ty < tx) {
        tx %= ty;
      } else {
        ty %= tx;
      }
    }
    if (sx == tx && sy <= ty && (ty - sy) % sx == 0) {
      return true;
    } else if (sy == ty && sx <= tx && (tx - sx) % sy == 0) {
      return true;
    } else {
      return false;
    }
  }
};

int main() { return 0; }
