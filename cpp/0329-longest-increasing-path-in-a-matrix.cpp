#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return 0;
    }
    int R = matrix.size();
    int C = matrix[0].size();
    vector<Node> nodes;
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        nodes.push_back(Node(r, c, matrix[r][c]));
      }
    }
    sort(nodes.begin(), nodes.end(), [](const Node &a, const Node &b) {
      return a.v != b.v ? a.v < b.v : (a.r != b.r ? a.r < b.r : a.c < b.c);
    });
    vector<vector<int>> dp(R, vector<int>(C, 1));
    int ans = 0;
    for (const Node &node : nodes) {
      int r = node.r;
      int c = node.c;
      int v = node.v;
      for (int i = 0; i < 4; ++i) {
        int nr = r + dirs[i][0];
        int nc = c + dirs[i][1];
        if (0 <= nr && nr < R && 0 <= nc && nc < C && matrix[nr][nc] < v) {
          dp[r][c] = max(dp[r][c], dp[nr][nc] + 1);
        }
      }
      ans = max(ans, dp[r][c]);
    }
    return ans;
  }

private:
  static constexpr int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  struct Node {
    int r;
    int c;
    int v;
    Node(int r, int c, int v) : r(r), c(c), v(v) {}
  };
};
