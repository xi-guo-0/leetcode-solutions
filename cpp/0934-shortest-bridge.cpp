#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int shortestBridge(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    bool found = false;
    queue<pair<int, int>> q;

    for (int i = 0; i < m && !found; ++i) {
      for (int j = 0; j < n && !found; ++j) {
        if (grid[i][j] == 1) {
          dfs(grid, i, j, q);
          found = true;
        }
      }
    }

    int level = 0;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
      int size = q.size();

      for (int k = 0; k < size; ++k) {
        auto [x, y] = q.front();
        q.pop();

        for (auto &dir : directions) {
          int nx = x + dir[0];
          int ny = y + dir[1];

          if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (grid[nx][ny] == 1) {
              return level;
            } else if (grid[nx][ny] == 0) {
              grid[nx][ny] = -1;
              q.push({nx, ny});
            }
          }
        }
      }

      level++;
    }

    return -1;
  }

private:
  void dfs(vector<vector<int>> &grid, int x, int y, queue<pair<int, int>> &q) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() ||
        grid[x][y] != 1) {
      return;
    }

    grid[x][y] = -1;

    q.push({x, y});

    dfs(grid, x - 1, y, q);
    dfs(grid, x + 1, y, q);
    dfs(grid, x, y - 1, q);
    dfs(grid, x, y + 1, q);
  }
};

int main() { return 0; }
