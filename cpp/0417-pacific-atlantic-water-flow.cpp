#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    if (heights.empty())
      return {};

    int m = heights.size();
    int n = heights[0].size();

    vector<vector<bool>> can_reach_pacific(m, vector<bool>(n, false));
    vector<vector<bool>> can_reach_atlantic(m, vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
      dfs(heights, can_reach_pacific, i, 0);
      dfs(heights, can_reach_atlantic, i, n - 1);
    }

    for (int j = 0; j < n; ++j) {
      dfs(heights, can_reach_pacific, 0, j);
      dfs(heights, can_reach_atlantic, m - 1, j);
    }

    vector<vector<int>> result;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (can_reach_pacific[i][j] && can_reach_atlantic[i][j]) {
          result.push_back({i, j});
        }
      }
    }

    return result;
  }

  void dfs(vector<vector<int>> &heights, vector<vector<bool>> &can_reach, int i,
           int j) {
    if (can_reach[i][j])
      return;

    can_reach[i][j] = true;

    int m = heights.size();
    int n = heights[0].size();

    static vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (const auto &dir : directions) {
      int ni = i + dir.first;
      int nj = j + dir.second;

      if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
          heights[ni][nj] >= heights[i][j]) {
        dfs(heights, can_reach, ni, nj);
      }
    }
  }
};
