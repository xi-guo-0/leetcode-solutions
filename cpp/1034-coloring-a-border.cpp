#include <functional>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col,
                                  int color) {
    int m = grid.size();
    int n = grid[0].size();
    int originalColor = grid[row][col];
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<pair<int, int>> borderCells;

    auto isBorder = [&](int x, int y) {
      return (x == 0 || x == m - 1 || y == 0 || y == n - 1) ||
             (grid[x - 1][y] != originalColor ||
              grid[x + 1][y] != originalColor ||
              grid[x][y - 1] != originalColor ||
              grid[x][y + 1] != originalColor);
    };

    function<void(int, int)> dfs = [&](int x, int y) {
      visited[x][y] = true;
      if (isBorder(x, y)) {
        borderCells.emplace_back(x, y);
      }
      vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
      for (auto &dir : directions) {
        int nx = x + dir.first;
        int ny = y + dir.second;
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] &&
            grid[nx][ny] == originalColor) {
          dfs(nx, ny);
        }
      }
    };

    dfs(row, col);

    for (auto &cell : borderCells) {
      grid[cell.first][cell.second] = color;
    }

    return grid;
  }
};

int main() { return 0; }
