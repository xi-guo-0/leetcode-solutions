#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class VirusCluster {
public:
  set<pair<int, int>> contaminatedCells;
  set<pair<int, int>> adjacentUncontaminatedCells;
  int wallCount = 0;
};

class Solution {
public:
  void exploreVirus(vector<vector<int>> &grid, int i, int j,
                    vector<vector<bool>> &visited, VirusCluster &cluster) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        visited[i][j] || grid[i][j] == -1)
      return;
    if (grid[i][j] == 0) {
      cluster.wallCount++;
      cluster.adjacentUncontaminatedCells.insert({i, j});
      return;
    }
    cluster.contaminatedCells.insert({i, j});
    visited[i][j] = true;
    exploreVirus(grid, i + 1, j, visited, cluster);
    exploreVirus(grid, i - 1, j, visited, cluster);
    exploreVirus(grid, i, j + 1, visited, cluster);
    exploreVirus(grid, i, j - 1, visited, cluster);
  }

  int containVirus(vector<vector<int>> &grid) {
    int wallsBuilt = 0;
    int numRows = grid.size(), numCols = grid[0].size();

    while (true) {
      vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));
      auto clusterComparator = [](const VirusCluster &cluster1,
                                  const VirusCluster &cluster2) {
        return cluster1.adjacentUncontaminatedCells.size() <
               cluster2.adjacentUncontaminatedCells.size();
      };
      priority_queue<VirusCluster, vector<VirusCluster>,
                     decltype(clusterComparator)>
          clustersPQ(clusterComparator);

      for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
          if (!visited[i][j] && grid[i][j] == 1) {
            VirusCluster currentCluster;
            exploreVirus(grid, i, j, visited, currentCluster);
            clustersPQ.push(currentCluster);
          }
        }
      }

      if (clustersPQ.empty())
        break;

      VirusCluster largestCluster = clustersPQ.top();
      clustersPQ.pop();
      for (const auto &cell : largestCluster.contaminatedCells) {
        grid[cell.first][cell.second] = -1;
      }
      wallsBuilt += largestCluster.wallCount;

      while (!clustersPQ.empty()) {
        VirusCluster currentCluster = clustersPQ.top();
        clustersPQ.pop();
        for (const auto &cell : currentCluster.adjacentUncontaminatedCells) {
          grid[cell.first][cell.second] = 1;
        }
      }
    }

    return wallsBuilt;
  }
};

int main() { return 0; }
