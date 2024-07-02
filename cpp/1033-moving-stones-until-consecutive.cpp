#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> numMovesStones(int a, int b, int c) {
    vector<int> v{a, b, c};
    sort(v.begin(), v.end());
    if (v[0] + 1 == v[1] && v[1] + 1 == v[2])
      return {0, 0};
    else if (v[1] <= v[0] + 2 || v[2] <= v[1] + 2)
      return {1, v[2] - v[0] - 2};
    return {2, v[2] - v[0] - 2};
  }
};

int main() { return 0; }
