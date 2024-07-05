#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
    vector<int> ans(n, 0);
    vector<vector<int>> g(n + 1);
    for (const auto &p : paths) {
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }
    for (int i = 1; i <= n; ++i) {
      set<int> s{1, 2, 3, 4};
      for (const auto &j : g[i])
        s.erase(ans[j - 1]);
      ans[i - 1] = *s.begin();
    }
    return ans;
  }
};

int main() { return 0; }