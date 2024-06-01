#include <iostream>

using namespace std;

class Solution {
public:
  int numTilings(const int N) {
    long long a = 1, b = 2, c = 5, t = 14;
    for (int i = 1; i < N; i++) {
      t = (a + 2 * c) % 1000000007;
      a = b, b = c, c = t;
    }
    return static_cast<int>(a);
  }
};

int main() { return 0; }
