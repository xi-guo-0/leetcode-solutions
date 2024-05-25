#include <algorithm>
#include <vector>

class UnionFind {
  std::vector<int> ancestor;

public:
  UnionFind(int n) : ancestor(n) {
    for (int i = 0; i < n; ++i) {
      ancestor[i] = i;
    }
  }

  void union_set(int index1, int index2) {
    ancestor[find_set(index1)] = find_set(index2);
  }

  int find_set(int index) {
    if (ancestor[index] != index) {
      ancestor[index] = find_set(ancestor[index]);
    }
    return ancestor[index];
  }
};

class Solution {
public:
  std::vector<int>
  findRedundantDirectedConnection(std::vector<std::vector<int>> &edges) {
    int nodesCount = edges.size();
    UnionFind uf(nodesCount + 1);
    std::vector<int> parent(nodesCount + 1);
    for (int i = 1; i <= nodesCount; ++i) {
      parent[i] = i;
    }
    int conflict = -1;
    int cycle = -1;
    for (int i = 0; i < nodesCount; ++i) {
      std::vector<int> edge = edges[i];
      int node1 = edge[0], node2 = edge[1];
      if (parent[node2] != node2) {
        conflict = i;
      } else {
        parent[node2] = node1;
        if (uf.find_set(node1) == uf.find_set(node2)) {
          cycle = i;
        } else {
          uf.union_set(node1, node2);
        }
      }
    }
    if (conflict < 0) {
      return {edges[cycle][0], edges[cycle][1]};
    } else {
      std::vector<int> conflictEdge = edges[conflict];
      if (cycle >= 0) {
        return {parent[conflictEdge[1]], conflictEdge[1]};
      } else {
        return {conflictEdge[0], conflictEdge[1]};
      }
    }
  }
};
