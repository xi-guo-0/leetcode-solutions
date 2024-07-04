#include <vector>

using namespace std;

class Solution {
public:
  bool isBoomerang(vector<vector<int>> &points) {
    vector<int> a = {points[1][0] - points[0][0], points[1][1] - points[0][1]};
    vector<int> b = {points[2][0] - points[0][0], points[2][1] - points[0][1]};
    return a[0] * b[1] != a[1] * b[0];
  }
};

int main() { return 0; }