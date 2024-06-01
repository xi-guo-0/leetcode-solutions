#include <vector>

using namespace std;

class Solution {
public:
  bool escapeGhosts(const vector<vector<int>> &ghosts,
                    const vector<int> &target) {
    const int distance = abs(target[0]) + abs(target[1]);
    for (const auto &p : ghosts)
      if (abs(p[0] - target[0]) + abs(p[1] - target[1]) <= distance)
        return false;
    return true;
  }
};

int main() {
  return 0;
}
