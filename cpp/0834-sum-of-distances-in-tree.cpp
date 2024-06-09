#include <functional>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    unordered_map<int, vector<int>> graph;
    vector<int> count(n, 0);
    vector<int> res(n, 0);

    for (const auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    function<void(int, int)> dfs1;
    function<void(int, int, int)> dfs2;

    dfs1 = [&](int cur, int parent) {
      count[cur] = 1;
      for (int child : graph[cur]) {
        if (child != parent) {
          dfs1(child, cur);
          count[cur] += count[child];
          res[cur] += res[child] + count[child];
        }
      }
    };

    dfs2 = [&](int cur, int parent, int n) {
      for (int child : graph[cur]) {
        if (child != parent) {
          res[child] = res[cur] + n - 2 * count[child];
          dfs2(child, cur, n);
        }
      }
    };

    dfs1(0, -1);
    dfs2(0, -1, n);

    return res;
  }
};

int main() { return 0; }
