class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int r = matrix.size() - 1;
    int c = 0;
    while (0 <= r && c < matrix[0].size()) {
      int value = matrix[r][c];
      if (value == target) {
        return true;
      } else if (value < target) {
        c += 1;
      } else {
        r -= 1;
      }
    }
    return false;
  }
};
