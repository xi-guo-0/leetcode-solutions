#include <vector>

using namespace std;

class Solution {
public:
  bool isOneBitCharacter(vector<int> &bits) {
    int i = 0;
    int n = bits.size() - 1;
    while (i < n) {
      if (bits[i] == 1) {
        i += 2;
      } else {
        i += 1;
      }
    }
    return i == n;
  }
};

int main() { return 0; }
