#include <algorithm>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);
    vector<int> inDegree(n, 0);
    vector<vector<int>> ancestors(n);

    for (const auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      inDegree[edge[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (inDegree[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      for (int neighbor : adj[node]) {
        ancestors[neighbor].push_back(node);
        ancestors[neighbor].insert(ancestors[neighbor].end(),
                                   ancestors[node].begin(),
                                   ancestors[node].end());

        sort(ancestors[neighbor].begin(), ancestors[neighbor].end());
        ancestors[neighbor].erase(
            unique(ancestors[neighbor].begin(), ancestors[neighbor].end()),
            ancestors[neighbor].end());

        if (--inDegree[neighbor] == 0) {
          q.push(neighbor);
        }
      }
    }

    return ancestors;
  }
};

int main() { return 0; }
