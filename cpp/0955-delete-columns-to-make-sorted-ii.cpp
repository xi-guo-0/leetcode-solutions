#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minDeletionSize(vector<string> &strs) {
    int rows = strs.size();
    int cols = strs[0].size();
    int result = 0;

    vector<bool> sorted(rows, false);

    for (int col = 0; col < cols; ++col) {
      bool valid = true;
      for (int row = 1; row < rows; ++row) {
        if (!sorted[row] && strs[row][col] < strs[row - 1][col]) {
          valid = false;
          break;
        }
      }

      if (valid) {
        for (int row = 1; row < rows; ++row) {
          if (strs[row][col] > strs[row - 1][col]) {
            sorted[row] = true;
          }
        }
      } else {
        ++result;
      }
    }

    return result;
  }
};

int main() { return 0; }
