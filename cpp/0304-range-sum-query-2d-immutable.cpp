#include <vector>

using namespace std;

class NumMatrix {
public:
  NumMatrix(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      R = 0;
      C = 0;
    } else {
      R = matrix.size();
      C = matrix[0].size();
    }
    m.resize(R + 1, std::vector<long>(C + 1, 0));
    for (int r = 1; r <= R; ++r) {
      for (int c = 1; c <= C; ++c) {
        m[r][c] =
            -m[r - 1][c - 1] + m[r - 1][c] + m[r][c - 1] + matrix[r - 1][c - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return static_cast<int>(m[row2 + 1][col2 + 1] - m[row1][col2 + 1] -
                            m[row2 + 1][col1] + m[row1][col1]);
  }

private:
  int R;
  int C;
  std::vector<std::vector<long>> m;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
