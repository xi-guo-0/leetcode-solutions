#include <vector>

using namespace std;

class Solution {
public:
  bool isRectangleOverlap(const vector<int> &rec1, const vector<int> &rec2) {
    return !(rec1[2] <= rec2[0] || rec1[3] <= rec2[1] || rec2[2] <= rec1[0] ||
             rec2[3] <= rec1[1]);
  }
};

int main() { return 0; }
