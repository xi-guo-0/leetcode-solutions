#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(const vector<vector<int>> &graph) {
    vector<vector<int>> result;
    vector<int> path(1, 0);
    dfs(graph, result, path, 0);
    return result;
  }

private:
  void dfs(const vector<vector<int>> &graph, vector<vector<int>> &result,
           vector<int> &path, int i) {
    if (i == graph.size() - 1) {
      result.push_back(path);
    }
    const vector<int> &v = graph[i];
    for (int j = 0; j < v.size(); j++) {
      path.push_back(v[j]);
      dfs(graph, result, path, v[j]);
      path.pop_back();
    }
  }
};

int main() { return 0; }
