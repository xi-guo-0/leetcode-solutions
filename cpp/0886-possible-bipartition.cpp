#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool possibleBipartition(int n, vector<vector<int>> &dislikes) {

    unordered_map<int, vector<int>> graph;
    for (const auto &dislike : dislikes) {
      graph[dislike[0]].push_back(dislike[1]);
      graph[dislike[1]].push_back(dislike[0]);
    }

    vector<int> colors(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
      if (colors[i] == 0 && !dfs(i, 1, colors, graph)) {
        return false;
      }
    }

    return true;
  }

private:
  bool dfs(int node, int color, vector<int> &colors,
           unordered_map<int, vector<int>> &graph) {

    colors[node] = color;

    for (int neighbor : graph[node]) {
      if (colors[neighbor] == color) {
        return false;
      }
      if (colors[neighbor] == 0 && !dfs(neighbor, -color, colors, graph)) {
        return false;
      }
    }

    return true;
  }
};

int main() { return 0; }
