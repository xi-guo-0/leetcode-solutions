#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int numBusesToDestination(vector<vector<int>> &routes, int source,
                            int target) {
    if (source == target) {
      return 0;
    }

    unordered_map<int, unordered_set<int>> stop_to_routes;
    for (int i = 0; i < routes.size(); ++i) {
      for (int stop : routes[i]) {
        stop_to_routes[stop].insert(i);
      }
    }

    queue<pair<int, int>> bfs_queue;
    unordered_set<int> visited_stops;
    unordered_set<int> visited_routes;

    bfs_queue.push({source, 0});
    visited_stops.insert(source);

    while (!bfs_queue.empty()) {
      auto [current_stop, buses] = bfs_queue.front();
      bfs_queue.pop();
      for (int route : stop_to_routes[current_stop]) {
        if (visited_routes.count(route)) {
          continue;
        }

        visited_routes.insert(route);

        for (int next_stop : routes[route]) {
          if (next_stop == target) {
            return buses + 1;
          }
          if (visited_stops.find(next_stop) == visited_stops.end()) {
            visited_stops.insert(next_stop);
            bfs_queue.push({next_stop, buses + 1});
          }
        }
      }
    }

    return -1;
  }
};

int main() { return 0; }
