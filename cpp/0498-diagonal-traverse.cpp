class Solution {
public:
  vector<int> findDiagonalOrder(const vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix.front().empty())
      return vector<int>();
    const int m = matrix.size(), n = matrix.front().size(), k = m + n - 1;
    vector<int> ans;
    bool upright = true;
    for (int line = 0; line < k; line++) {
      if (upright) {
        for (int r = min(m - 1, line), c = line - r; 0 <= r && c < n; r--, c++)
          ans.push_back(matrix[r][c]);
      } else {
        for (int c = min(n - 1, line), r = line - c; r < m && 0 <= c; r++, c--)
          ans.push_back(matrix[r][c]);
      }
      upright = !upright;
    }

    return ans;
  }
};
