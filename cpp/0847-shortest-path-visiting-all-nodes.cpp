#include <algorithm>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct pair_hash {
  template <class T1, class T2> size_t operator()(const pair<T1, T2> &p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};

class Solution {
public:
  int shortestPathLength(vector<vector<int>> &graph) {
    int N = graph.size();
    queue<pair<int, int>> queue;
    unordered_map<pair<int, int>, int, pair_hash> dist;

    for (int x = 0; x < N; ++x)
      queue.push({1 << x, x});

    int full_cover = (1 << N) - 1;
    int min_steps = N * N;
    while (!queue.empty()) {
      auto [cover, head] = queue.front();
      queue.pop();
      int d = dist[{cover, head}];
      if (cover == full_cover) {
        min_steps = min(min_steps, d);
        continue;
      }
      for (int child : graph[head]) {
        int cover2 = cover | (1 << child);
        if (!dist.count({cover2, child}) || d + 1 < dist[{cover2, child}]) {
          dist[{cover2, child}] = d + 1;
          queue.push({cover2, child});
        }
      }
    }
    return min_steps;
  }
};

int main() { return 0; }
