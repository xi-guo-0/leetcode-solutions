#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int catMouseGame(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(n, vector<int>(2, 1)));
    vector<vector<vector<int>>> ind(n,
                                    vector<vector<int>>(n, vector<int>(2, 0)));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 2 && j == 1) {
          int daasd = 0;
        }
        ind[i][j][0] = graph[j].size();
        for (auto &x : graph[j]) {
          if (x == 0) {
            ind[i][j][0]--;
          }
        }
        ind[i][j][1] = graph[i].size();
        for (auto &x : graph[i]) {
          if (x == 0) {
            ind[i][j][1]--;
          }
        }
      }
    }
    queue<vector<int>> q;
    for (int i = 0; i < n; i++) {
      dp[i][0][0] = 0;
      dp[i][0][1] = 0;
      q.push({i, 0, 0, 0});
      q.push({i, 0, 1, 0});
      if (i == 0) {
        continue;
      }
      dp[i][i][0] = 2;
      dp[i][i][1] = 2;
      q.push({i, i, 0, 2});
      q.push({i, i, 1, 2});
    }
    while (q.size() > 0) {
      auto node = q.front();
      q.pop();
      int &turn = node[2];
      int &cat = node[0];
      int &mouse = node[1];
      int &color = node[3];
      for (auto &x : graph[turn % 2 == 1 ? mouse : cat]) {
        auto tmp = vector<int>(4, 0);
        int &p_turn = tmp[2] = (turn + 1) % 2;
        int &p_mouse = tmp[1] = turn % 2 == 1 ? x : mouse;
        int &p_cat = tmp[0] = turn % 2 == 0 ? x : cat;
        if (p_cat == 2 && p_mouse == 1 && p_turn == 0) {
          int ggg = 0;
        }
        if (p_cat == 0) {
          continue;
        }
        if (dp[p_cat][p_mouse][p_turn] != 1) {
          continue;
        }
        if (p_turn == 1) {
          if (color == 2) {
            dp[p_cat][p_mouse][p_turn] = 2;
            tmp[3] = 2;
            q.push(tmp);
          } else {
            ind[p_cat][p_mouse][p_turn]--;
            if (ind[p_cat][p_mouse][p_turn] == 0) {
              dp[p_cat][p_mouse][p_turn] = 0;
              tmp[3] = 0;
              q.push(tmp);
            }
          }
        } else {
          if (color == 0) {
            dp[p_cat][p_mouse][p_turn] = 0;
            tmp[3] = 0;
            q.push(tmp);
          } else {
            ind[p_cat][p_mouse][p_turn]--;
            if (ind[p_cat][p_mouse][p_turn] == 0) {
              dp[p_cat][p_mouse][p_turn] = 2;
              tmp[3] = 2;
              q.push(tmp);
            }
          }
        }
      }
    }
    int r = dp[2][1][0];
    if (r == 0) {
      r = 1;
    } else if (r == 1) {
      r = 0;
    }
    return r;
  }
};

int main() { return 0; }
