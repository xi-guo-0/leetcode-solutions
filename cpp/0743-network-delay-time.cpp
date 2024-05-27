#include <iostream>
#include <limits>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    unordered_map<int, vector<pair<int, int>>> graph;
    for (const auto &time : times) {
      int u = time[0], v = time[1], w = time[2];
      graph[u].emplace_back(v, w);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(n + 1, numeric_limits<int>::max());

    pq.emplace(0, k);
    dist[k] = 0;

    while (!pq.empty()) {
      auto [currentDist, u] = pq.top();
      pq.pop();

      if (currentDist > dist[u]) {
        continue;
      }

      for (const auto &[v, w] : graph[u]) {
        int newDist = currentDist + w;
        if (newDist < dist[v]) {
          dist[v] = newDist;
          pq.emplace(newDist, v);
        }
      }
    }

    int maxDist = 0;
    for (int i = 1; i <= n; ++i) {
      if (dist[i] == numeric_limits<int>::max()) {
        return -1;
      }
      maxDist = max(maxDist, dist[i]);
    }

    return maxDist;
  }
};

int main() {
  vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
  int n = 4;
  int k = 2;
  Solution solution;
  solution.networkDelayTime(times, n, k);
  return 0;
}
