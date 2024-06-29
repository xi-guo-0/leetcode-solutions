#include <array>
#include <vector>

using namespace std;

class Solution {
public:
  int uniquePathsIII(vector<vector<int>> &grid) {
    init(grid);
    dfs(startRow, startCol, 0, grid);
    return pathCount;
  }

private:
  void dfs(int r, int c, int cnt, vector<vector<int>> &grid) {
    if (r == endRow && c == endCol) {
      if (cnt == emptyCount)
        pathCount++;
      return;
    }

    int temp = grid[r][c];
    grid[r][c] = kObstacle;

    for (int k = 0; k < directions.size(); ++k) {
      int nr = r + directions[k][0];
      int nc = c + directions[k][1];

      if (isValidMove(nr, nc, grid)) {
        dfs(nr, nc, cnt + 1, grid);
      }
    }

    grid[r][c] = temp;
  }

  bool isValidMove(int r, int c, const vector<vector<int>> &grid) const {
    return (r >= 0 && r < rows && c >= 0 && c < cols &&
            grid[r][c] != kObstacle);
  }

  void init(const vector<vector<int>> &grid) {
    rows = grid.size();
    cols = grid[0].size();
    emptyCount = 1;
    pathCount = 0;

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        switch (grid[i][j]) {
        case kStarting:
          startRow = i;
          startCol = j;
          break;
        case kEnding:
          endRow = i;
          endCol = j;
          break;
        case kEmpty:
          ++emptyCount;
          break;
        }
      }
    }
  }

  const array<array<int, 2>, 4> directions{{{0, 1}, {-1, 0}, {0, -1}, {1, 0}}};
  static constexpr int kStarting = 1;
  static constexpr int kEnding = 2;
  static constexpr int kEmpty = 0;
  static constexpr int kObstacle = -1;

  int startRow, startCol;
  int endRow, endCol;
  int rows, cols;
  int emptyCount;
  int pathCount;
};

int main() { return 0; }
