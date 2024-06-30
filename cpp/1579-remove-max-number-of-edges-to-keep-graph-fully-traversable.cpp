#include <numeric>
#include <vector>

using namespace std;

class UnionFind {
public:
  vector<int> parent;
  vector<int> rank;

  UnionFind(int n) : parent(n + 1), rank(n + 1, 0) {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  bool unite(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    if (root_x != root_y) {
      if (rank[root_x] > rank[root_y]) {
        parent[root_y] = root_x;
      } else if (rank[root_x] < rank[root_y]) {
        parent[root_x] = root_y;
      } else {
        parent[root_y] = root_x;
      }
      return true;
    }
    return false;
  }

  bool is_connected(int n) {
    int root = find(1);
    for (int i = 2; i <= n; ++i) {
      if (find(i) != root) {
        return false;
      }
    }
    return true;
  }
};

class Solution {
public:
  int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
    UnionFind alice(n);
    UnionFind bob(n);
    int edges_used = 0;

    for (const auto &edge : edges) {
      if (edge[0] == 3) {
        bool used_a = alice.unite(edge[1], edge[2]);
        bool used_b = bob.unite(edge[1], edge[2]);
        if (used_a || used_b) {
          edges_used += 1;
        }
      }
    }

    for (const auto &edge : edges) {
      if (edge[0] == 1) {
        if (alice.unite(edge[1], edge[2])) {
          edges_used += 1;
        }
      } else if (edge[0] == 2) {
        if (bob.unite(edge[1], edge[2])) {
          edges_used += 1;
        }
      }
    }

    if (alice.is_connected(n) && bob.is_connected(n)) {
      return edges.size() - edges_used;
    } else {
      return -1;
    }
  }
};

int main() { return 0; }
