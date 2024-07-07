#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    unordered_map<string, int> patternCount;
    int maxRows = 0;

    for (auto &row : matrix) {
      string pattern1, pattern2;
      for (int val : row) {
        pattern1 += to_string(val);
        pattern2 += to_string(1 - val);
      }
      string normalizedPattern = pattern1 < pattern2 ? pattern1 : pattern2;
      maxRows = max(maxRows, ++patternCount[normalizedPattern]);
    }

    return maxRows;
  }
};