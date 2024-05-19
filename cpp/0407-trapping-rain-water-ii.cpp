#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int trapRainWater(vector<vector<int>> &heightMap) {
    if (heightMap.empty() || heightMap[0].empty())
      return 0;

    int m = heightMap.size();
    int n = heightMap[0].size();
    int volume = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
          pq.push({heightMap[i][j], {i, j}});
          visited[i][j] = true;
        }
      }
    }

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!pq.empty()) {
      auto cell = pq.top();
      pq.pop();
      int height = cell.first;
      int row = cell.second.first;
      int col = cell.second.second;

      for (auto &dir : directions) {
        int newRow = row + dir.first;
        int newCol = col + dir.second;

        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
            !visited[newRow][newCol]) {
          visited[newRow][newCol] = true;

          int newHeight = max(height, heightMap[newRow][newCol]);
          volume += max(0, newHeight - heightMap[newRow][newCol]);

          pq.push({newHeight, {newRow, newCol}});
        }
      }
    }

    return volume;
  }
};
