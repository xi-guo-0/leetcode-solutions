#include <iostream>

using namespace std;

class Solution {
public:
  int reachNumber(int target) {
    if (target < 0)
      target = -target;
    for (int i = 0, n = 0;; i++) {
      n = (i * i + i) / 2;
      if (target <= n && n % 2 == target % 2)
        return i;
    }
    return 0;
  }
};

int main() { return 0; }
