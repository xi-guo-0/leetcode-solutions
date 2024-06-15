#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n) {
    unordered_map<int, vector<pair<int, int>>> graph;

    for (auto &edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    priority_queue<pair<int, int>> pq;
    pq.push({maxMoves, 0});

    unordered_map<int, int> dist;
    dist[0] = maxMoves;

    while (!pq.empty()) {
      auto [movesLeft, node] = pq.top();
      pq.pop();

      if (dist[node] < movesLeft)
        continue;

      for (auto &[neighbor, weight] : graph[node]) {
        int newMovesLeft = movesLeft - weight - 1;

        if (newMovesLeft >= 0 &&
            (dist.count(neighbor) == 0 || newMovesLeft > dist[neighbor])) {
          dist[neighbor] = newMovesLeft;
          pq.push({newMovesLeft, neighbor});
        }
      }
    }

    int reachableNodesCount = 0;

    for (auto &[node, maxMovesLeft] : dist) {
      if (maxMovesLeft >= 0)
        reachableNodesCount++;
    }

    for (auto &edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      int countU = dist.count(u) ? max(0, dist[u]) : 0;
      int countV = dist.count(v) ? max(0, dist[v]) : 0;
      reachableNodesCount += min(w, countU + countV);
    }

    return reachableNodesCount;
  }
};

int main() { return 0; }
