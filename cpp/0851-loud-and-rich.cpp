#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
    int n = quiet.size();
    vector<vector<int>> graph(n);

    for (const auto &r : richer) {
      graph[r[1]].push_back(r[0]);
    }

    vector<int> result(n, -1);

    function<int(int)> dfs = [&](int node) -> int {
      if (result[node] != -1)
        return result[node];

      result[node] = node;
      for (int neighbor : graph[node]) {
        int candidate = dfs(neighbor);
        if (quiet[candidate] < quiet[result[node]]) {
          result[node] = candidate;
        }
      }

      return result[node];
    };

    for (int i = 0; i < n; ++i) {
      dfs(i);
    }

    return result;
  }
};

int main() { return 0; }
