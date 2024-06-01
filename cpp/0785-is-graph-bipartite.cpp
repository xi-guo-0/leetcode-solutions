#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
  vector<int> color;

public:
  bool isBipartite(vector<vector<int>> &graph) {
    color.assign(graph.size(), 0);
    for (int i = 0; i < graph.size(); ++i) {
      if (color[i] == 0 && !dfs(i, 1, graph))
        return false;
    }
    return true;
  }

  bool dfs(int node, int c, vector<vector<int>> &graph) {
    if (color[node] != 0)
      return color[node] == c;

    color[node] = c;
    for (int neighbor : graph[node]) {
      if (!dfs(neighbor, -c, graph))
        return false;
    }
    return true;
  }
};

int main() { return 0; }
