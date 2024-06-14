#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int robotSim(const vector<int> &commands,
               const vector<vector<int>> &obstacles) {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int x = 0, y = 0, di = 0;

    set<pair<int, int>> obstacleSet;
    for (const vector<int> &obstacle : obstacles)
      obstacleSet.insert(make_pair(obstacle[0], obstacle[1]));

    int ans = 0;
    for (const int cmd : commands) {
      if (cmd == -2)
        di = (di + 3) % 4;
      else if (cmd == -1)
        di = (di + 1) % 4;
      else {
        for (int k = 0; k < cmd; ++k) {
          int nx = x + dx[di];
          int ny = y + dy[di];
          if (obstacleSet.find(make_pair(nx, ny)) == obstacleSet.end()) {
            x = nx;
            y = ny;
            ans = max(ans, x * x + y * y);
          }
        }
      }
    }

    return ans;
  }
};

int main() { return 0; }
