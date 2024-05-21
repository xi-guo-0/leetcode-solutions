#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
    if (nums.size() * nums[0].size() != r * c) {
      return nums;
    }
    vector<vector<int>> result(r, vector<int>(c));
    int row = 0;
    int col = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums[i].size(); j++) {
        result[row][col] = nums[i][j];
        col++;
        if (col == c) {
          col = 0;
          row++;
        }
      }
    }
    return result;
  }
};
