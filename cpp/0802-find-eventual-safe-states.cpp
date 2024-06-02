#include <vector>

using namespace std;

class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> color(n, 0);
    vector<int> safeNodes;

    for (int i = 0; i < n; ++i) {
      if (isSafe(i, graph, color)) {
        safeNodes.push_back(i);
      }
    }

    return safeNodes;
  }

private:
  bool isSafe(int node, vector<vector<int>> &graph, vector<int> &color) {
    if (color[node] > 0) {
      return color[node] == 2;
    }
    color[node] = 1;
    for (int neighbor : graph[node]) {
      if (color[neighbor] == 2)
        continue;
      if (color[neighbor] == 1 || !isSafe(neighbor, graph, color)) {
        return false;
      }
    }
    color[node] = 2;
    return true;
  }
};

int main() { return 0; }
