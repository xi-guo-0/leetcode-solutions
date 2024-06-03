#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class UnionFind {
public:
  UnionFind(int n) : parent(n), rank(n, 0), size(n, 1) {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
      if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
      } else if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
        size[rootY] += size[rootX];
      } else {
        parent[rootY] = rootX;
        rank[rootX]++;
        size[rootX] += size[rootY];
      }
    }
  }

  int getSize(int x) { return size[find(x)]; }

private:
  vector<int> parent;
  vector<int> rank;
  vector<int> size;
};

class Solution {
public:
  vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> gridCopy = grid;
    for (const auto &hit : hits) {
      gridCopy[hit[0]][hit[1]] = 0;
    }

    UnionFind uf(m * n + 1);
    for (int j = 0; j < n; ++j) {
      if (gridCopy[0][j] == 1) {
        uf.unionSet(j, m * n);
      }
    }

    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (gridCopy[i][j] == 1) {
          if (gridCopy[i - 1][j] == 1) {
            uf.unionSet(i * n + j, (i - 1) * n + j);
          }
          if (j > 0 && gridCopy[i][j - 1] == 1) {
            uf.unionSet(i * n + j, i * n + j - 1);
          }
        }
      }
    }

    vector<int> result(hits.size());
    for (int k = hits.size() - 1; k >= 0; --k) {
      int i = hits[k][0];
      int j = hits[k][1];

      if (grid[i][j] == 0) {
        result[k] = 0;
      } else {
        int prevRoofSize = uf.getSize(m * n);
        if (i == 0) {
          uf.unionSet(j, m * n);
        }
        for (const auto &dir : directions) {
          int x = i + dir.first;
          int y = j + dir.second;
          if (x >= 0 && x < m && y >= 0 && y < n && gridCopy[x][y] == 1) {
            uf.unionSet(i * n + j, x * n + y);
          }
        }
        gridCopy[i][j] = 1;
        int newRoofSize = uf.getSize(m * n);
        result[k] = max(0, newRoofSize - prevRoofSize - 1);
      }
    }

    return result;
  }
};

int main() { return 0; }
