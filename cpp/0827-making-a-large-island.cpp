#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int largestIsland(vector<vector<int>> &grid) {
    int n = grid.size();
    int maxArea = 0;

    unordered_map<int, int> area;
    int islandID = 2;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          int currArea = dfs(grid, i, j, islandID);
          area[islandID++] = currArea;
          maxArea = max(maxArea, currArea);
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          unordered_set<int> connectedIslands;
          int currArea = 1;
          for (auto [dx, dy] : directions) {
            int x = i + dx, y = j + dy;
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 1) {
              connectedIslands.insert(grid[x][y]);
            }
          }
          for (int island : connectedIslands) {
            currArea += area[island];
          }
          maxArea = max(maxArea, currArea);
        }
      }
    }

    return maxArea;
  }

private:
  vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  int dfs(vector<vector<int>> &grid, int i, int j, int islandID) {
    int n = grid.size();
    if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) {
      return 0;
    }
    grid[i][j] = islandID;
    int area = 1;
    for (auto [dx, dy] : directions) {
      area += dfs(grid, i + dx, j + dy, islandID);
    }
    return area;
  }
};

int main() { return 0; }
