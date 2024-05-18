#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    std::unordered_map<int, std::unordered_set<int>> graph;
    if (edges.empty()) {
      return {0};
    }

    for (const auto &edge : edges) {
      graph[edge[0]].insert(edge[1]);
      graph[edge[1]].insert(edge[0]);
    }

    std::vector<int> leaves;
    for (const auto &node_neighbors : graph) {
      if (node_neighbors.second.size() == 1) {
        leaves.push_back(node_neighbors.first);
      }
    }

    while (n > 2) {
      n -= leaves.size();
      std::vector<int> next_leaves;
      for (int leaf : leaves) {
        int tmp = *(graph[leaf].begin());
        graph[tmp].erase(leaf);
        if (graph[tmp].size() == 1) {
          next_leaves.push_back(tmp);
        }
      }
      leaves = next_leaves;
    }
    return leaves;
  }
};
