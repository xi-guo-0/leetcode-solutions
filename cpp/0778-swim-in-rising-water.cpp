#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

vector<int> dir = {0, 1, 0, -1, 0};

class Solution {
public:
  int swimInWater(vector<vector<int>> &grid) {
    int n = grid.size();
    auto cmp = [](const tuple<int, int, int> &a,
                  const tuple<int, int, int> &b) {
      return get<0>(a) > get<0>(b);
    };
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   decltype(cmp)>
        pq(cmp);
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    pq.emplace(grid[0][0], 0, 0);
    visited[0][0] = true;

    while (!pq.empty()) {
      auto [t, x, y] = pq.top();
      pq.pop();

      if (x == n - 1 && y == n - 1)
        return t;

      for (int i = 0; i < 4; ++i) {
        int nx = x + dir[i], ny = y + dir[i + 1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
          visited[nx][ny] = true;
          pq.emplace(max(t, grid[nx][ny]), nx, ny);
        }
      }
    }
    return -1;
  }
};

int main() { return 0; }
